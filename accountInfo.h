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

class accountInfo
{
public:
    MYSQL         *mysql;
    MYSQL_STMT    *stmt;
    MYSQL_BIND    bind_param[10];
    MYSQL_BIND    bind[50];
    MYSQL_RES     *prepare_meta_result;
    unsigned long length[50];
    my_bool       is_null[50];
  
    
    MYSQL_TIME    cht;
    MYSQL_TIME    crt;
    int socket = -1;

    int id = 0;
    int parking_lot_id = 0;
    char ticket[20] = "";
    int ticket_type = 0;
    char plate[12] = "";
    time_t start_time = -1;
    time_t end_time = -1;
    int access_group = 255;
    int inner_group = 255;
    int time_group = 255;
    int lots_group = 65535;
    int account_state = 0;
    int  parking_type = 0;
    char addr[100] = "";
    char description[100] = "";
    char email[64] = "";
    char phone[16] = "";
    char owner_name[20] = "";
    char hour_ticket_num[20] = "";
    int hour_ticket_type = 0;
    int lot_id = 0;
    char online_member[20] = "";
    int prepaid_charge_rule = 0;
    int monthly_charge_rule = 0;
    int ticket_lpbind = 0;
    int monthly_type = 255;
    time_t limit_time = -1;
    char photo_id[255] = "";
    char add_info1[255] = "";
    char add_info2[255] = "";
    int is_deleted = 0;
    time_t created_at = -1;
    int created_by = 0;
    time_t deleted_at = -1;
    int deleted_by = -1;
    time_t updated_at = -1;
    int updated_by = 0; 
    
    
    
    accountInfo(MYSQL *mysql);

    ~accountInfo();
        
    int Insert_accountInfo();
    
    int Insert_update_accountInfo();
    
    int Select_account_by_ID(int index);
    
    int Select_account_by_ticket(std::string ticket);
    
    int Select_account_by_plate(std::string plate, int match_plate);
    
    int Select_account_by_ID_park_lot_id(int index, int park_lot_id);

    int Select_account_by_ticket_park_lot_id(std::string _ticket, int park_lot_id);

    int Select_account_by_plate_park_lot_id(std::string curr_plate, int match_plate, int park_lot_id);
    
    int Delete_accountInfo();
    
    int print_account_info_variables();
            
};