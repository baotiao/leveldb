#include "leveldb/db.h"
#include <iostream>
#include <assert.h>
#include <string>

#include <time.h>
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;

#include "leveldb/write_batch.h"

using namespace std;
int main(void)
{
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    //options.max_open_files = 2;
    //options.error_if_exists = true;

    std::string key1 = "czz", key2 = "baotiao"; 
    std::string value = "tiancai";
    leveldb::Status s = leveldb::DB::Open(options, "/tmp/testdb", &db);


    time_t now = time(0);

    printf(ctime(&now));


    time_t after = (int)now + 100;
    printf(ctime(&after));
    printf("%u\n", (int)now);


    key1 = "a2";
    value = "b2";
    s = db->Put(leveldb::WriteOptions(), key1, value, 5);

    //sleep(6);
    string value1;
    s = db->Get(leveldb::ReadOptions(), key1, &value1);

    debug(value1);
    //char value[100];
    //db->GetProperty(property, p_value);
    //for (int i = 0; i < 2; i++) {
    //    //value = snprintf(value, sizeof(value), "%d%c", (int)now, 
    //    value = char(i + 'a');
    //    key1 = char('a');
    //    debug(key1);
    //    debug(value);
    //}
    //s = db->Put(leveldb::WriteOptions(), key1, value);

    //s = db->Get(leveldb::ReadOptions(), key1, &value);
    //s = db->Delete(leveldb::WriteOptions(), "czza");
    //if (s.ok()) {
    //    leveldb::WriteBatch batch;
    //    batch.Delete(key1);
    //    batch.Put(key2, value);
    //    s = db->Write(leveldb::WriteOptions(), &batch);
    //}
    //std::string value1;
    //s = db->Get(leveldb::ReadOptions(), key2, &value1);

    //printf("values %s\n", value1.c_str());
    leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
    for (it->SeekToFirst(); it->Valid(); it->Next())
    {
        cout << "output all keys " << it->key().ToString() << ": " << it->value().ToString() << endl;
    }
    delete it;
    delete db;
    return 0;
}
