#include <iostream>
#include <ctime>
#include <string.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <mysql/mysql.h>
#include "dashou.h"
#define Reference_date 946684800

class camera
{
public:
    MYSQL         *mysql;
    MYSQL_STMT    *stmt;
    MYSQL_BIND    bind_param[10];
    MYSQL_BIND    bind[20];
    MYSQL_RES     *prepare_meta_result;
    unsigned long length[20];
    my_bool       is_null[20];
    
    MYSQL_TIME    crt;

    int id = 0;
    int parking_lot_id = 0;
    char ip[22] = "";
    char name[50] = "";
    char user_name[20] = "";
    char password[20] = "";
    int is_deleted = 0;
    time_t created_at = Reference_date;
    int created_by = 0;
    time_t deleted_at = -1;
    int deleted_by = -1;
    time_t updated_at = Reference_date;
    int updated_by = 0;
    std::vector<int> site_list;
    
    
    camera(MYSQL *mysql);

    ~camera();

    int Insert_Update_Camera_type();
    
    int Select_Camera_type_by_id(int _id);
        
    int Select_Camera_type_by_address(int address);
    
    int Select_Camera_type_by_address_park_lot_id(int _address, int park_lot_id);
    
    int Select_sites_Connected_to_camera();

    int Delete_Camera_type();
    
    int print_camera_variables();
    
};