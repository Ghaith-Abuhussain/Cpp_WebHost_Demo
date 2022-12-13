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

class account_state
{
public:
    MYSQL         *mysql;
    MYSQL_STMT    *stmt;
    MYSQL_BIND    bind_param[10];
    MYSQL_BIND    bind[60];
    MYSQL_RES     *prepare_meta_result;
    unsigned long length[60];
    my_bool       is_null[60];
  
    
    MYSQL_TIME    cht;
    MYSQL_TIME    crt;
    int socket = -1;

    int id = 0;
    int parking_lot_id = 0;
    char ticket[20] = "";
    int ticket_type = 0;
    char plate[12] = "";
    int parking_type = 64;
    int present_type = 0;
    time_t intime = -1;
    int inserial = 0;
    time_t outtime = -1;
    int outserial = 0;
    time_t pay_time = -1;
    int pay_serial = 0;
    int paid_sum = 0;
    int charge_type = 255;
    time_t inner_intime = -1;
    int inner_inserial = 0;
    time_t inner_outtime = -1;
    int inner_outserial = 0;
    int limit_sum = 0;
    char online_order[255] = "";
    int insite = 255;
    int charge_site = 255;
    int inner_insite = 255;
    int inner_outsite = 255;
    int prepaid_balance = 0;
    int l2_id = 255;
    int prepaid_account_id = 65535;
    char hour_ticket_num[20] = "";
    int hour_ticket_type = 0;
    int total_sum = 0;
    int is_deleted = 0;
    time_t created_at = Reference_date;
    int created_by = 0; 
    time_t deleted_at = -1;
    int deleted_by = -1;
    time_t updated_at = Reference_date;
    int updated_by = 0;

    account_state(MYSQL *mysql);

    ~account_state();
        
    int Insert_update_account_state();
    
    int Select_account_state_by_ID(int index);
    
    int Select_account_state_by_ticket(std::string ticket);
    
    int Select_account_state_by_plate(std::string plate, int match_plate);
    
    int Select_account_state_by_ID_park_lot_id(int index, int park_lot_id);

    int Select_account_state_by_ticket_park_lot_id(std::string _ticket, int park_lot_id);

    int Select_account_state_by_plate_park_lot_id(std::string curr_plate, int match_plate, int park_lot_id);
    
    int Delete_account_state();
    
    int print_account_state_variables();
};