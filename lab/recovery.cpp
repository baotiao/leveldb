#include "leveldb/db.h"
#include <iostream>
#include <assert.h>
#include <string>
#include <errno.h>
#include <string.h>

#include "leveldb/write_batch.h"

using namespace std;
int main()
{
    leveldb::DB* db;
    leveldb::Options options;
    //options.create_if_missing = true;
    //options.error_if_exists = false;

    leveldb::Status s = leveldb::DB::Open(options, "/tmp/testdb", &db);
    std::string value1;

    if (s.ok()) {
        printf("Open testdb OK\n");
    } else {
        printf("open error %d %s\n", errno, strerror(errno));
        return -1;
    }
    //printf("values %s\n", value1.c_str());
    leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
    for (it->SeekToFirst(); it->Valid(); it->Next())
    {
        cout << it->key().ToString() << ": " << it->value().ToString() << endl;
    }
    delete it;
    delete db;
    return 0;
}
