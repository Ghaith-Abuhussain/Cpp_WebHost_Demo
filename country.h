#include "dashou.h"
#include <iostream>
#include <time.h>
#include <string.h>
#include <sstream>
#include <iomanip> 
#include <vector>
#include <mysql/mysql.h>


class country
{
    MYSQL         *mysql;
    MYSQL_STMT    *stmt;
    MYSQL_BIND    bind_param[15];
    MYSQL_BIND    bind[15];
    MYSQL_RES     *prepare_meta_result;
    unsigned long length[15];
    my_bool       is_null[15];
    
    MYSQL_TIME    created_t;
    MYSQL_TIME    deleted_t;
    MYSQL_TIME    updated_t;
public:
    int id = 0;
    char name_ar[50] = "";
    char name_en[50] = "";
    char code[3] = "";
    char flag[200] = "";
    int is_deleted = 0;
    time_t created_at = 0;
    int created_by = 0;
    time_t deleted_at = -1;
    int deleted_by = -1;
    time_t updated_at = 0;
    int updated_by = 0;
    
    country(MYSQL *_mysql);

    ~country();
    
    void Print_country();
    
    bool select_country(int _id);
    
    bool insert_update_country();
    
    bool delete_country();
};