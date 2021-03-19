//
// Created by mayintong on 2021/3/17.
//

#include <string>
#include "kvstore.h"
#include <iostream>

void KvStore::set(const std::string& key, const std::string& value) {
    auto p = this->writer.tellp();

    unsigned long keyLen = key.length();
    this->writer.write(reinterpret_cast<const char *>(& keyLen), sizeof(keyLen));

    this->writer << key;

    unsigned long valueLen = value.length();
    this->writer.write(reinterpret_cast<const char *>(& valueLen), sizeof(valueLen));

    this->writer << value;
    this->writer.flush();

    auto commandPos = std::make_shared<CommandPos>(p, this->writer.tellp() - p);
    this->map[key] = *commandPos;

}

std::string KvStore::get(const std::string& key) {

    this->reader.seekg(this->map[key].pos, std::ios::beg);
    auto temp = new char[8];
    this->reader.read(temp, 8);
    auto keyLen = static_cast<unsigned long>(*temp);

    this->reader.seekg(this->map[key].pos + 8 + keyLen, std::ios::beg);
    this->reader.read(temp, 8);
    auto valueLen = static_cast<unsigned long>(*temp);

    this->reader.seekg(this->map[key].pos + 8 + keyLen + 8, std::ios::beg);

    char* value = new char[valueLen];
    this->reader.read(value, valueLen);
    return value;

}

void KvStore::remove(const std::string& key) {
    return;
}

KvStore::KvStore(const std::string& path) {
    this->writer.open(path, std::ios::binary | std::ios::out);
    this->reader.open(path, std::ios::binary | std::ios::in);

}

void KvStore::compact() {

}

