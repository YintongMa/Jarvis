//
// Created by mayintong on 2021/3/17.
//

#ifndef JARVIS_KVSTORE_H
#define JARVIS_KVSTORE_H
#include <unordered_map>
#include <fstream>

class KvStore {

    class CommandPos {
        public:
            size_t len;
            size_t pos;
            CommandPos(){}
            CommandPos(size_t pos, size_t len){
                this->pos = pos;
                this->len = len;
            }

    };

private:

    std::unordered_map<std::string, KvStore::CommandPos> map;
    std::ofstream writer;
    std::ifstream reader;

public:

    KvStore(const std::string& path);

    /// Sets the value of a string key to a string.
    /// If the key already exists, the previous value will be overwritten.
    void set(const std::string& key, const std::string& value);

    /// Gets the string value of a given string key.
    /// Returns `None` if the given key does not exist.
    std::string get(const std::string& key);

    /// Remove a given key.
    void remove(const std::string& key);

    void compact();



};



#endif //JARVIS_KVSTORE_H
