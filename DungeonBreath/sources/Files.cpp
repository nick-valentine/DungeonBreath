#include "../headers/Files.h"

std::queue<File *> FileManager::my_queue;
bool FileManager::dead = false;

sf::Thread *SpawnFileThread()
{
	sf::Thread *file_thread = new sf::Thread(&FileThread);
	file_thread->launch();
	return file_thread;
}

void KillFileThread(sf::Thread *file_thread)
{
	FileManager::kill();
	file_thread->wait();
	return;
}

void FileThread()
{
	FileManager my_file_manager;
	my_file_manager.run();
	return;
}

File::File()
{

}

void File::init(std::string file_name, std::vector<std::string> data)
{
	this->my_mutex.lock();
	this->file_name = file_name;
	this->data = data;
	this->my_mutex.unlock();
}

void File::QueueWrite()
{
	this->my_mutex.lock();
	write = true;
	my_ready = false;
	FileManager::my_queue.push(this);
	this->my_mutex.unlock();
}

void File::QueueRead()
{
	this->my_mutex.lock();
	write = false;
	my_ready = false;
	FileManager::my_queue.push(this);
	this->my_mutex.unlock();
}

std::string File::get_file_name() const
{
	return this->file_name;
}

std::vector<std::string> File::get_data() const
{
	return this->data;
}

bool File::ready() const
{
	return this->my_ready;
}

void File::set_file_name(std::string x)
{
	this->my_mutex.lock();
	this->file_name = x;
	this->my_mutex.unlock();
}

void File::set_data(std::vector<std::string> x)
{
	this->my_mutex.lock();
	this->data = x;
	this->my_mutex.unlock();
}

FileManager::FileManager()
{

}

void FileManager::run()
{
	while(!dead || !my_queue.empty())
	{
		if(!my_queue.empty())
		{
			File *x = my_queue.front();
			x->my_mutex.lock();
			my_queue.pop();
			if(x->write == true)
			{
				std::ofstream my_file;
				my_file.open(x->file_name.c_str());
				
				for(int i = 0; i < x->data.size(); ++i)
				{
					my_file<<x->data[i]<<"\n";
				}
				
				my_file.close();
				x->my_ready = true;
			}
			else
			{
				x->data.clear();
				std::ifstream my_file;
				my_file.open(x->file_name.c_str());
				
				std::string temp;
				while(my_file.good())
				{
					getline(my_file,temp);
					x->data.push_back(temp);
				}
				
				my_file.close();
				x->my_ready = true;
			}
			x->my_mutex.unlock();
		}
		else
		{
			sf::sleep(sf::milliseconds(10));
		}
	}
}

void FileManager::kill()
{
	dead = true;
}

