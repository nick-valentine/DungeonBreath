#ifndef FILES_H
#define FILES_H

#include <SFML/System.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

sf::Thread *SpawnFileThread();
void KillFileThread(sf::Thread *file_thread);
void FileThread();

class File
{
 friend class FileManager;
 public:
 	File();
 	void init(std::string file_name, std::vector<std::string> data);
 	
 	void QueueWrite();
 	void QueueRead();
 	
 	std::string get_file_name() const;
 	std::vector<std::string> get_data() const;
 	bool ready() const;
 	
 	void set_file_name(std::string x);
 	void set_data(std::vector<std::string> x);
 private:
 	std::string file_name;
 	std::vector<std::string> data;
 	bool write;
 	bool my_ready;
 	sf::Mutex my_mutex;
};

class FileManager
{
 friend class File;
 public:
 	FileManager();
 	void run();
 	static void kill();
 private:
 	static std::queue<File *> my_queue;
 	static bool dead;
};

#endif //FILES_H
