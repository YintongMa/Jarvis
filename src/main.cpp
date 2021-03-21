#include <iostream>
#include "storage/kvstore.h"
#include <fstream>
#include <vector>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string k1 = "k123555";
    std::string v1 = "v13133";
    auto kv =std::make_shared<KvStore>("/Users/mayintong/Workspace/Jarvis/src/storage/log/db");
    kv->set(k1,v1);
    kv->set("123","344");
    std::cout << kv->get(k1) << std::endl;
    std::cout << kv->get("123") << std::endl;
    return 0;
}
