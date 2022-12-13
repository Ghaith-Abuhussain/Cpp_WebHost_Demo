#include "accountInfo.h"

accountInfo::accountInfo(MYSQL *_mysql)
{
    mysql = _mysql;
}

accountInfo::~accountInfo()
{
    
}

int accountInfo::Insert_update_accountInfo()
{
    std::string statment = "INSERT INTO `account_info` (`id`,`parking_lot_id` ,`ticket`,`ticket_type`,`plate`,`start_time`,`end_time`,`access_group`,`inner_group`,`time_group`,`lots_group`,`account_state`,`parking_type` ,`addr` ,`description` ,`email` ,`phone` ,`owner_name` ,`hour_ticket_num`,`hour_ticket_type`,`lot_id` ,`online_member` ,`prepaid_charge_rule` ,`monthly_charge_rule`,`ticket_lpbind`,`monthly_type` ,`limit_time`,`photo_id`,`add_info1` ,`add_info2` ,`is_deleted` ,`created_at`,`created_by` ,`deleted_at` ,`deleted_by` ,`updated_at` ,`updated_by`) VALUES ( ?, ?, ?, ?, ?, FROM_UNIXTIME(?), FROM_UNIXTIME(?), ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, FROM_UNIXTIME(?), ?, ?, ?, ?, FROM_UNIXTIME(?),?,FROM_UNIXTIME(?),?,FROM_UNIXTIME(?),?) ON DUPLICATE KEY UPDATE id = VALUES(id),parking_lot_id = VALUES(parking_lot_id),ticket = VALUES(ticket),ticket_type = VALUES(ticket_type),plate = VALUES(plate),start_time = VALUES(start_time),end_time = VALUES(end_time),access_group = VALUES(access_group),inner_group = VALUES(inner_group),time_group = VALUES(time_group),lots_group = VALUES(lots_group),account_state = VALUES(account_state),parking_type = VALUES(parking_type),addr = VALUES(addr),description = VALUES(description),email = VALUES(email),phone = VALUES(phone),owner_name = VALUES(owner_name),hour_ticket_num = VALUES(hour_ticket_num),hour_ticket_type = VALUES(hour_ticket_type),lot_id = VALUES(lot_id),online_member = VALUES(online_member),prepaid_charge_rule = VALUES(prepaid_charge_rule),monthly_charge_rule = VALUES(monthly_charge_rule),ticket_lpbind = VALUES(ticket_lpbind),monthly_type = VALUES(monthly_type),limit_time = VALUES(limit_time),photo_id = VALUES(photo_id),add_info1 = VALUES(add_info1),add_info2 = VALUES(add_info2),is_deleted = VALUES(is_deleted),created_at = VALUES (created_at),created_by = VALUES(created_by),deleted_at = VALUES(deleted_at),deleted_by = VALUES(deleted_by),updated_at = VALUES(updated_at),updated_by  = VALUES(updated_by)";
    if (mysql != NULL) 
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3780;
            }
        }
        catch(...)
        {
            return -3780;
        }
        
        try
        {
            if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
            {
                try
                {
                    memset(bind, 0, sizeof(bind));
                    memset(is_null,0,sizeof(is_null));

                    bind[0].buffer_type= MYSQL_TYPE_LONG;
                    bind[0].buffer= (char *)&id;
                    bind[0].is_null= &is_null[0];
                    bind[0].length= &length[0];

                    bind[1].buffer_type= MYSQL_TYPE_LONG;
                    bind[1].buffer= (char *)&parking_lot_id;
                    bind[1].is_null= &is_null[1];
                    bind[1].length= &length[1];

                    bind[2].buffer_type= MYSQL_TYPE_STRING;
                    bind[2].buffer= (char *)ticket;
                    bind[2].buffer_length= 20;
                    bind[2].is_null= &is_null[2];
                    length[2] = strlen(ticket);
                    bind[2].length= &length[2];

                    bind[3].buffer_type= MYSQL_TYPE_LONG;
                    bind[3].buffer= (char *)&ticket_type;
                    bind[3].is_null= &is_null[3];
                    bind[3].length= &length[3];

                    /* SHORT COLUMN */
                    bind[4].buffer_type= MYSQL_TYPE_STRING;
                    bind[4].buffer= (char *)plate;
                    bind[4].buffer_length= 12;
                    bind[4].is_null= &is_null[4];
                    length[4] = strlen(plate);
                    bind[4].length= &length[4];

                    /* SHORT COLUMN */
                    bind[5].buffer_type= MYSQL_TYPE_LONG;
                    bind[5].buffer= (char *)&start_time;
                    is_null[5] = (start_time == -1);
                    bind[5].is_null= &is_null[5];
                    bind[5].length= &length[5];

                    /* SHORT COLUMN */
                    bind[6].buffer_type= MYSQL_TYPE_LONG;
                    bind[6].buffer= (char *)&end_time;
                    is_null[6] = (end_time == -1);
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    /* SHORT COLUMN */
                    bind[7].buffer_type= MYSQL_TYPE_LONG;
                    bind[7].buffer= (char *)&access_group;
                    bind[7].is_null= &is_null[7];
                    bind[7].length= &length[7];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inner_group;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[9].buffer_type= MYSQL_TYPE_LONG;
                    bind[9].buffer= (char *)&time_group;
                    bind[9].is_null= &is_null[9];
                    bind[9].length= &length[9];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&lots_group;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* SHORT COLUMN */
                    bind[11].buffer_type= MYSQL_TYPE_LONG;
                    bind[11].buffer= (char *)&account_state;
                    bind[11].is_null= &is_null[11];
                    bind[11].length= &length[11];

                    /* STRING COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&parking_type;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* SHORT COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_STRING;
                    bind[13].buffer= (char *)addr;
                    bind[13].buffer_length= 100;
                    bind[13].is_null= &is_null[13];
                    length[13] = strlen(addr);
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_STRING;
                    bind[14].buffer= (char *)description;
                    bind[14].buffer_length= 100;
                    bind[14].is_null= &is_null[14];
                    length[14] = strlen(description);
                    bind[14].length= &length[14];

                    /* STRING COLUMN */
                    bind[15].buffer_type= MYSQL_TYPE_STRING;
                    bind[15].buffer= (char *)email;
                    bind[15].buffer_length= 64;
                    bind[15].is_null= &is_null[15];
                    length[15] = strlen(email);
                    bind[15].length= &length[15];

                    /* INTEGER COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_STRING;
                    bind[16].buffer= (char *)phone;
                    bind[16].buffer_length= 16;
                    bind[16].is_null= &is_null[16];
                    length[16] = strlen(phone);
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[17].buffer_type= MYSQL_TYPE_STRING;
                    bind[17].buffer= (char *)owner_name;
                    bind[17].buffer_length= 20;
                    bind[17].is_null= &is_null[17];
                    length[17] = strlen(owner_name);
                    bind[17].length= &length[17];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_STRING;
                    bind[18].buffer= (char *)hour_ticket_num;
                    bind[18].buffer_length= 20;
                    bind[18].is_null= &is_null[18];
                    length[18] = strlen(hour_ticket_num);
                    bind[18].length= &length[18];

                    /* SHORT COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&hour_ticket_type;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_LONG;
                    bind[20].buffer= (char *)&lot_id;
                    bind[20].is_null= &is_null[20];
                    bind[20].length= &length[20];

                    /* TIMESTAMP COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_STRING;
                    bind[21].buffer= (char *)online_member;
                    bind[21].buffer_length= 20;
                    bind[21].is_null= &is_null[21];
                    length[21] = strlen(online_member);
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&prepaid_charge_rule;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&monthly_charge_rule;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&ticket_lpbind;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&monthly_type;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[26].buffer_type= MYSQL_TYPE_LONG;
                    bind[26].buffer= (char *)&limit_time;
                    is_null[26] = (limit_time == -1);
                    bind[26].is_null= &is_null[26];
                    bind[26].length= &length[26];

                    /* VARCHAR COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_STRING;
                    bind[27].buffer= (char *)photo_id;
                    bind[27].buffer_length= 255;
                    bind[27].is_null= &is_null[27];
                    length[27] = strlen(photo_id);
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)add_info1;
                    bind[28].buffer_length= 255;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(add_info1);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_STRING;
                    bind[29].buffer= (char *)add_info2;
                    bind[29].buffer_length= 255;
                    bind[29].is_null= &is_null[29];
                    length[29] = strlen(add_info2);
                    bind[29].length= &length[29];

                    /* SHORT COLUMN */
                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&is_deleted;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    /* SHORT COLUMN */
                    bind[31].buffer_type= MYSQL_TYPE_LONG;
                    bind[31].buffer= (char *)&created_at;
                    bind[31].is_null= &is_null[31];
                    bind[31].length= &length[31];

                    /* SHORT COLUMN */
                    bind[32].buffer_type= MYSQL_TYPE_LONG;
                    bind[32].buffer= (char *)&created_by;
                    bind[32].is_null= &is_null[32];
                    bind[32].length= &length[32];

                    /* SHORT COLUMN */
                    bind[33].buffer_type= MYSQL_TYPE_LONG;
                    bind[33].buffer= (char *)&deleted_at;
                    is_null[33] = (deleted_at == -1);
                    bind[33].is_null= &is_null[33];
                    bind[33].length= &length[33];

                    /* SHORT COLUMN */
                    bind[34].buffer_type= MYSQL_TYPE_LONG;
                    bind[34].buffer= (char *)&deleted_by;
                    is_null[34] = (deleted_by == -1);
                    bind[34].is_null= &is_null[34];
                    bind[34].length= &length[34];

                    /* SHORT COLUMN */
                    bind[35].buffer_type= MYSQL_TYPE_LONG;
                    bind[35].buffer= (char *)&updated_at;
                    bind[35].is_null= &is_null[35];
                    bind[35].length= &length[35];

                    /* SHORT COLUMN */
                    bind[36].buffer_type= MYSQL_TYPE_LONG;
                    bind[36].buffer= (char *)&updated_by;
                    bind[36].is_null= &is_null[36];
                    bind[36].length= &length[36];
                }
                catch(...)
                {
                    return -3797;
                }
                
                try
                {
                    if (mysql_stmt_bind_param(stmt, bind))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3782;
                    }
                }
                catch(...)
                {
                    return -3782;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    std::cout<<param_count<<std::endl;
                    if (param_count != 37) /* validate parameter count */
                    {
                        std::cout<<"param count " << param_count <<std::endl;
                        //fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3783;
                    }
                }
                catch(...)
                {
                    return -3783;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3784;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3784;
                }
                
                try
                {
                    if (mysql_stmt_affected_rows(stmt) == 1)
                    {
                        fprintf(stderr, "account info %d with %d inserted\n", parking_lot_id, id);
                    }
                    if (mysql_stmt_affected_rows(stmt) != 1)
                    {
                        fprintf(stderr, "account info %d with %d updated\n", parking_lot_id, id);
                    }
                }
                catch(...)
                {
                    return -3785;
                }
                
                
            }
            else
            {
                return -3781;
            }
        }
        catch(...)
        {
            return -3781;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3486;
        }
        
    }
    else
    {
        return -3779;
    }
    return 0;
}

int accountInfo::Select_account_by_ID(int index)
{
    int id_;
    std::string statment = "SELECT *,UNIX_TIMESTAMP(start_time),UNIX_TIMESTAMP(end_time),UNIX_TIMESTAMP(limit_time),UNIX_TIMESTAMP(created_at),UNIX_TIMESTAMP(deleted_at),UNIX_TIMESTAMP(updated_at) FROM account_info WHERE id=?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3702;
            }
        }
        catch(...)
        {
            return -3702;
        }
        
        try
        {
            if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
            {
                try
                {
                    memset(bind_param, 0, sizeof(bind));
                    bind_param[0].buffer_type= MYSQL_TYPE_LONG;
                    bind_param[0].buffer= (char *)&id_;

                    if (mysql_stmt_bind_param(stmt, bind_param))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3704;
                    }
                    id_ = index;
                }
                catch(...)
                {
                    return -3704;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 1) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3705;
                    }
                }
                catch(...)
                {
                    return -3705;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3706;
                    }
                }
                catch(...)
                {
                    return -3706;
                }
                
                try
                {
                    int column_count= mysql_num_fields(prepare_meta_result);
                    std::cout << column_count << std::endl;
                    if (column_count != 43) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -3707;
                    }
                }
                catch(...)
                {
                    return -3707;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3708;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3708;
                }
                
                try
                {
                    memset(bind, 0, sizeof(bind));
                    memset(is_null,0,sizeof(is_null));
                    bind[0].buffer_type= MYSQL_TYPE_LONG;
                    bind[0].buffer= (char *)&id;
                    bind[0].is_null= &is_null[0];
                    bind[0].length= &length[0];

                    bind[1].buffer_type= MYSQL_TYPE_LONG;
                    bind[1].buffer= (char *)&parking_lot_id;
                    bind[1].is_null= &is_null[1];
                    bind[1].length= &length[1];

                    bind[2].buffer_type= MYSQL_TYPE_STRING;
                    bind[2].buffer= (char *)ticket;
                    bind[2].buffer_length= 20;
                    bind[2].is_null= &is_null[2];
                    length[2] = strlen(ticket);
                    bind[2].length= &length[2];

                    bind[3].buffer_type= MYSQL_TYPE_LONG;
                    bind[3].buffer= (char *)&ticket_type;
                    bind[3].is_null= &is_null[3];
                    bind[3].length= &length[3];

                    /* SHORT COLUMN */
                    bind[4].buffer_type= MYSQL_TYPE_STRING;
                    bind[4].buffer= (char *)plate;
                    bind[4].buffer_length= 12;
                    bind[4].is_null= &is_null[4];
                    length[4] = strlen(plate);
                    bind[4].length= &length[4];

                    /* SHORT COLUMN */
                    bind[37].buffer_type= MYSQL_TYPE_LONG;
                    bind[37].buffer= (char *)&start_time;
                    is_null[37] = (start_time == -1);
                    bind[37].is_null= &is_null[37];
                    bind[37].length= &length[37];

                    /* SHORT COLUMN */
                    bind[38].buffer_type= MYSQL_TYPE_LONG;
                    bind[38].buffer= (char *)&end_time;
                    is_null[38] = (end_time == -1);
                    bind[38].is_null= &is_null[38];
                    bind[38].length= &length[38];

                    /* SHORT COLUMN */
                    bind[7].buffer_type= MYSQL_TYPE_LONG;
                    bind[7].buffer= (char *)&access_group;
                    bind[7].is_null= &is_null[7];
                    bind[7].length= &length[7];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inner_group;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[9].buffer_type= MYSQL_TYPE_LONG;
                    bind[9].buffer= (char *)&time_group;
                    bind[9].is_null= &is_null[9];
                    bind[9].length= &length[9];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&lots_group;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* SHORT COLUMN */
                    bind[11].buffer_type= MYSQL_TYPE_LONG;
                    bind[11].buffer= (char *)&account_state;
                    bind[11].is_null= &is_null[11];
                    bind[11].length= &length[11];

                    /* STRING COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&parking_type;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* SHORT COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_STRING;
                    bind[13].buffer= (char *)addr;
                    bind[13].buffer_length= 100;
                    bind[13].is_null= &is_null[13];
                    length[13] = strlen(addr);
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_STRING;
                    bind[14].buffer= (char *)description;
                    bind[14].buffer_length= 100;
                    bind[14].is_null= &is_null[14];
                    length[14] = strlen(description);
                    bind[14].length= &length[14];

                    /* STRING COLUMN */
                    bind[15].buffer_type= MYSQL_TYPE_STRING;
                    bind[15].buffer= (char *)email;
                    bind[15].buffer_length= 64;
                    bind[15].is_null= &is_null[15];
                    length[15] = strlen(email);
                    bind[15].length= &length[15];

                    /* INTEGER COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_STRING;
                    bind[16].buffer= (char *)phone;
                    bind[16].buffer_length= 16;
                    bind[16].is_null= &is_null[16];
                    length[16] = strlen(phone);
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[17].buffer_type= MYSQL_TYPE_STRING;
                    bind[17].buffer= (char *)owner_name;
                    bind[17].buffer_length= 20;
                    bind[17].is_null= &is_null[17];
                    length[17] = strlen(owner_name);
                    bind[17].length= &length[17];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_STRING;
                    bind[18].buffer= (char *)hour_ticket_num;
                    bind[18].buffer_length= 20;
                    bind[18].is_null= &is_null[18];
                    length[18] = strlen(hour_ticket_num);
                    bind[18].length= &length[18];

                    /* SHORT COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&hour_ticket_type;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_LONG;
                    bind[20].buffer= (char *)&lot_id;
                    bind[20].is_null= &is_null[20];
                    bind[20].length= &length[20];

                    /* TIMESTAMP COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_STRING;
                    bind[21].buffer= (char *)online_member;
                    bind[21].buffer_length= 20;
                    bind[21].is_null= &is_null[21];
                    length[21] = strlen(online_member);
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&prepaid_charge_rule;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&monthly_charge_rule;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&ticket_lpbind;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&monthly_type;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[39].buffer_type= MYSQL_TYPE_LONG;
                    bind[39].buffer= (char *)&limit_time;
                    is_null[39] = (limit_time == -1);
                    bind[39].is_null= &is_null[39];
                    bind[39].length= &length[39];

                    /* VARCHAR COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_STRING;
                    bind[27].buffer= (char *)photo_id;
                    bind[27].buffer_length= 255;
                    bind[27].is_null= &is_null[27];
                    length[27] = strlen(photo_id);
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)add_info1;
                    bind[28].buffer_length= 255;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(add_info1);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_STRING;
                    bind[29].buffer= (char *)add_info2;
                    bind[29].buffer_length= 255;
                    bind[29].is_null= &is_null[29];
                    length[29] = strlen(add_info2);
                    bind[29].length= &length[29];

                    /* SHORT COLUMN */
                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&is_deleted;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    /* SHORT COLUMN */
                    bind[40].buffer_type= MYSQL_TYPE_LONG;
                    bind[40].buffer= (char *)&created_at;
                    bind[40].is_null= &is_null[40];
                    bind[40].length= &length[40];

                    /* SHORT COLUMN */
                    bind[32].buffer_type= MYSQL_TYPE_LONG;
                    bind[32].buffer= (char *)&created_by;
                    bind[32].is_null= &is_null[32];
                    bind[32].length= &length[32];

                    /* SHORT COLUMN */
                    bind[41].buffer_type= MYSQL_TYPE_LONG;
                    bind[41].buffer= (char *)&deleted_at;
                    is_null[41] = (deleted_at == -1);
                    bind[41].is_null= &is_null[41];
                    bind[41].length= &length[41];

                    /* SHORT COLUMN */
                    bind[34].buffer_type= MYSQL_TYPE_LONG;
                    bind[34].buffer= (char *)&deleted_by;
                    is_null[34] = (deleted_by == -1);
                    bind[34].is_null= &is_null[34];
                    bind[34].length= &length[34];

                    /* SHORT COLUMN */
                    bind[42].buffer_type= MYSQL_TYPE_LONG;
                    bind[42].buffer= (char *)&updated_at;
                    bind[42].is_null= &is_null[42];
                    bind[42].length= &length[42];

                    /* SHORT COLUMN */
                    bind[36].buffer_type= MYSQL_TYPE_LONG;
                    bind[36].buffer= (char *)&updated_by;
                    bind[36].is_null= &is_null[36];
                    bind[36].length= &length[36];
                }
                catch(...)
                {
                    return -3795;
                }
                
                try
                {
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3709;
                    }
                }
                catch(...)
                {
                    return -3709;
                }
                
                try
                {
                    if (mysql_stmt_store_result(stmt))
                    {
                      fprintf(stderr, " mysql_stmt_store_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3710;
                    }
                }
                catch(...)
                {
                    return -3710;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -3711;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -3712;
                }
                
                
            }
            else
            {
                return -3703;
            }
        }
        catch(...)
        {
            return -3703;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3712;
        }
        
    }
    else
    {
        return -3701;
    }
    if(id == 0)
        return -1;
    return 0;
}

int accountInfo::Select_account_by_ticket(std::string _ticket)
{
    char ticket_[20];
    std::string statment = "SELECT *,UNIX_TIMESTAMP(start_time),UNIX_TIMESTAMP(end_time),UNIX_TIMESTAMP(limit_time),UNIX_TIMESTAMP(created_at),UNIX_TIMESTAMP(deleted_at),UNIX_TIMESTAMP(updated_at) FROM account_info WHERE ticket=?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3728;
            }
        }
        catch(...)
        {
            return -3728;
        }
        
        try
        {
            if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
            {
                try
                {
                    memset(bind_param, 0, sizeof(bind));
                    bind_param[0].buffer_type= MYSQL_TYPE_STRING;
                    bind_param[0].buffer= (char *)ticket_;
                    bind_param[0].buffer_length= strlen(_ticket.c_str());

                    if (mysql_stmt_bind_param(stmt, bind_param))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3730;
                    }
                    strcpy( ticket_, _ticket.c_str());
                }
                catch(...)
                {
                    return -3730;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 1) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3731;
                    }
                }
                catch(...)
                {
                    return -3731;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3732;
                    }
                }
                catch(...)
                {
                    return -3732;
                }
                
                try
                {
                    int column_count= mysql_num_fields(prepare_meta_result);
                    //std::cout << column_count << std::endl;
                    if (column_count != 43) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -3733;
                    }
                }
                catch(...)
                {
                    return -3733;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3734;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3734;
                }
                
                try
                {
                    memset(bind, 0, sizeof(bind));
                    memset(is_null,0,sizeof(is_null));
                    bind[0].buffer_type= MYSQL_TYPE_LONG;
                    bind[0].buffer= (char *)&id;
                    bind[0].is_null= &is_null[0];
                    bind[0].length= &length[0];

                    bind[1].buffer_type= MYSQL_TYPE_LONG;
                    bind[1].buffer= (char *)&parking_lot_id;
                    bind[1].is_null= &is_null[1];
                    bind[1].length= &length[1];

                    bind[2].buffer_type= MYSQL_TYPE_STRING;
                    bind[2].buffer= (char *)ticket;
                    bind[2].buffer_length= 20;
                    bind[2].is_null= &is_null[2];
                    length[2] = strlen(ticket);
                    bind[2].length= &length[2];

                    bind[3].buffer_type= MYSQL_TYPE_LONG;
                    bind[3].buffer= (char *)&ticket_type;
                    bind[3].is_null= &is_null[3];
                    bind[3].length= &length[3];

                    /* SHORT COLUMN */
                    bind[4].buffer_type= MYSQL_TYPE_STRING;
                    bind[4].buffer= (char *)plate;
                    bind[4].buffer_length= 12;
                    bind[4].is_null= &is_null[4];
                    length[4] = strlen(plate);
                    bind[4].length= &length[4];

                    /* SHORT COLUMN */
                    bind[37].buffer_type= MYSQL_TYPE_LONG;
                    bind[37].buffer= (char *)&start_time;
                    is_null[37] = (start_time == -1);
                    bind[37].is_null= &is_null[37];
                    bind[37].length= &length[37];

                    /* SHORT COLUMN */
                    bind[38].buffer_type= MYSQL_TYPE_LONG;
                    bind[38].buffer= (char *)&end_time;
                    is_null[38] = (end_time == -1);
                    bind[38].is_null= &is_null[38];
                    bind[38].length= &length[38];

                    /* SHORT COLUMN */
                    bind[7].buffer_type= MYSQL_TYPE_LONG;
                    bind[7].buffer= (char *)&access_group;
                    bind[7].is_null= &is_null[7];
                    bind[7].length= &length[7];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inner_group;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[9].buffer_type= MYSQL_TYPE_LONG;
                    bind[9].buffer= (char *)&time_group;
                    bind[9].is_null= &is_null[9];
                    bind[9].length= &length[9];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&lots_group;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* SHORT COLUMN */
                    bind[11].buffer_type= MYSQL_TYPE_LONG;
                    bind[11].buffer= (char *)&account_state;
                    bind[11].is_null= &is_null[11];
                    bind[11].length= &length[11];

                    /* STRING COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&parking_type;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* SHORT COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_STRING;
                    bind[13].buffer= (char *)addr;
                    bind[13].buffer_length= 100;
                    bind[13].is_null= &is_null[13];
                    length[13] = strlen(addr);
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_STRING;
                    bind[14].buffer= (char *)description;
                    bind[14].buffer_length= 100;
                    bind[14].is_null= &is_null[14];
                    length[14] = strlen(description);
                    bind[14].length= &length[14];

                    /* STRING COLUMN */
                    bind[15].buffer_type= MYSQL_TYPE_STRING;
                    bind[15].buffer= (char *)email;
                    bind[15].buffer_length= 64;
                    bind[15].is_null= &is_null[15];
                    length[15] = strlen(email);
                    bind[15].length= &length[15];

                    /* INTEGER COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_STRING;
                    bind[16].buffer= (char *)phone;
                    bind[16].buffer_length= 16;
                    bind[16].is_null= &is_null[16];
                    length[16] = strlen(phone);
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[17].buffer_type= MYSQL_TYPE_STRING;
                    bind[17].buffer= (char *)owner_name;
                    bind[17].buffer_length= 20;
                    bind[17].is_null= &is_null[17];
                    length[17] = strlen(owner_name);
                    bind[17].length= &length[17];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_STRING;
                    bind[18].buffer= (char *)hour_ticket_num;
                    bind[18].buffer_length= 20;
                    bind[18].is_null= &is_null[18];
                    length[18] = strlen(hour_ticket_num);
                    bind[18].length= &length[18];

                    /* SHORT COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&hour_ticket_type;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_LONG;
                    bind[20].buffer= (char *)&lot_id;
                    bind[20].is_null= &is_null[20];
                    bind[20].length= &length[20];

                    /* TIMESTAMP COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_STRING;
                    bind[21].buffer= (char *)online_member;
                    bind[21].buffer_length= 20;
                    bind[21].is_null= &is_null[21];
                    length[21] = strlen(online_member);
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&prepaid_charge_rule;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&monthly_charge_rule;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&ticket_lpbind;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&monthly_type;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[39].buffer_type= MYSQL_TYPE_LONG;
                    bind[39].buffer= (char *)&limit_time;
                    is_null[39] = (limit_time == -1);
                    bind[39].is_null= &is_null[39];
                    bind[39].length= &length[39];

                    /* VARCHAR COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_STRING;
                    bind[27].buffer= (char *)photo_id;
                    bind[27].buffer_length= 255;
                    bind[27].is_null= &is_null[27];
                    length[27] = strlen(photo_id);
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)add_info1;
                    bind[28].buffer_length= 255;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(add_info1);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_STRING;
                    bind[29].buffer= (char *)add_info2;
                    bind[29].buffer_length= 255;
                    bind[29].is_null= &is_null[29];
                    length[29] = strlen(add_info2);
                    bind[29].length= &length[29];

                    /* SHORT COLUMN */
                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&is_deleted;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    /* SHORT COLUMN */
                    bind[40].buffer_type= MYSQL_TYPE_LONG;
                    bind[40].buffer= (char *)&created_at;
                    bind[40].is_null= &is_null[40];
                    bind[40].length= &length[40];

                    /* SHORT COLUMN */
                    bind[32].buffer_type= MYSQL_TYPE_LONG;
                    bind[32].buffer= (char *)&created_by;
                    bind[32].is_null= &is_null[32];
                    bind[32].length= &length[32];

                    /* SHORT COLUMN */
                    bind[41].buffer_type= MYSQL_TYPE_LONG;
                    bind[41].buffer= (char *)&deleted_at;
                    is_null[41] = (deleted_at == -1);
                    bind[41].is_null= &is_null[41];
                    bind[41].length= &length[41];

                    /* SHORT COLUMN */
                    bind[34].buffer_type= MYSQL_TYPE_LONG;
                    bind[34].buffer= (char *)&deleted_by;
                    is_null[34] = (deleted_by == -1);
                    bind[34].is_null= &is_null[34];
                    bind[34].length= &length[34];

                    /* SHORT COLUMN */
                    bind[42].buffer_type= MYSQL_TYPE_LONG;
                    bind[42].buffer= (char *)&updated_at;
                    bind[42].is_null= &is_null[42];
                    bind[42].length= &length[42];

                    /* SHORT COLUMN */
                    bind[36].buffer_type= MYSQL_TYPE_LONG;
                    bind[36].buffer= (char *)&updated_by;
                    bind[36].is_null= &is_null[36];
                    bind[36].length= &length[36];
                }
                catch(...)
                {
                    return -3795;
                }
                
                try
                {
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3735;
                    }
                }
                catch(...)
                {
                    return -3735;
                }
                
                try
                {
                    if (mysql_stmt_store_result(stmt))
                    {
                      fprintf(stderr, " mysql_stmt_store_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return false;
                    }
                }
                catch(...)
                {
                    return -3736;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -3737;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -3738;
                }
                
                
            }
            else
            {
                return -3729;
            }
        }
        catch(...)
        {
            return -3729;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3739;
        }
        
    }
    else
    {
        return -3727;
    }
    if(id == 0)
        return -1;
    //std::cout << id << std::endl;
    return 0;
}

int accountInfo::Select_account_by_plate(std::string curr_plate, int match_plate)
{
    char plate_[12];
    std::string statment = "SELECT *,UNIX_TIMESTAMP(start_time),UNIX_TIMESTAMP(end_time),UNIX_TIMESTAMP(limit_time),UNIX_TIMESTAMP(created_at),UNIX_TIMESTAMP(deleted_at),UNIX_TIMESTAMP(updated_at) FROM account_info WHERE SUBSTR(plate,1," + std::to_string(match_plate) +")=?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3454;
            }
        }
        catch(...)
        {
            return -3454;
        }
        
        try
        {
            if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
            {
                try
                {
                    memset(bind_param, 0, sizeof(bind));
                    bind_param[0].buffer_type= MYSQL_TYPE_STRING;
                    bind_param[0].buffer= (char *)plate_;
                    bind_param[0].buffer_length= strlen(curr_plate.c_str());

                    if (mysql_stmt_bind_param(stmt, bind_param))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3756;
                    }
                    strncpy( plate_, curr_plate.c_str(), match_plate);
                }
                catch(...)
                {
                    return -3756;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 1) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3757;
                    }
                }
                catch(...)
                {
                    return -3757;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3758;
                    }
                }
                catch(...)
                {
                    return -3758;
                }
                
                try
                {
                    int column_count= mysql_num_fields(prepare_meta_result);
                    if (column_count != 43) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -3759;
                    }
                }
                catch(...)
                {
                    return -3759;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3760;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3760;
                }
                
                try
                {
                    memset(bind, 0, sizeof(bind));
                    memset(is_null,0,sizeof(is_null));
                    bind[0].buffer_type= MYSQL_TYPE_LONG;
                    bind[0].buffer= (char *)&id;
                    bind[0].is_null= &is_null[0];
                    bind[0].length= &length[0];

                    bind[1].buffer_type= MYSQL_TYPE_LONG;
                    bind[1].buffer= (char *)&parking_lot_id;
                    bind[1].is_null= &is_null[1];
                    bind[1].length= &length[1];

                    bind[2].buffer_type= MYSQL_TYPE_STRING;
                    bind[2].buffer= (char *)ticket;
                    bind[2].buffer_length= 20;
                    bind[2].is_null= &is_null[2];
                    length[2] = strlen(ticket);
                    bind[2].length= &length[2];

                    bind[3].buffer_type= MYSQL_TYPE_LONG;
                    bind[3].buffer= (char *)&ticket_type;
                    bind[3].is_null= &is_null[3];
                    bind[3].length= &length[3];

                    /* SHORT COLUMN */
                    bind[4].buffer_type= MYSQL_TYPE_STRING;
                    bind[4].buffer= (char *)plate;
                    bind[4].buffer_length= 12;
                    bind[4].is_null= &is_null[4];
                    length[4] = strlen(plate);
                    bind[4].length= &length[4];

                    /* SHORT COLUMN */
                    bind[37].buffer_type= MYSQL_TYPE_LONG;
                    bind[37].buffer= (char *)&start_time;
                    is_null[37] = (start_time == -1);
                    bind[37].is_null= &is_null[37];
                    bind[37].length= &length[37];

                    /* SHORT COLUMN */
                    bind[38].buffer_type= MYSQL_TYPE_LONG;
                    bind[38].buffer= (char *)&end_time;
                    is_null[38] = (end_time == -1);
                    bind[38].is_null= &is_null[38];
                    bind[38].length= &length[38];

                    /* SHORT COLUMN */
                    bind[7].buffer_type= MYSQL_TYPE_LONG;
                    bind[7].buffer= (char *)&access_group;
                    bind[7].is_null= &is_null[7];
                    bind[7].length= &length[7];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inner_group;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[9].buffer_type= MYSQL_TYPE_LONG;
                    bind[9].buffer= (char *)&time_group;
                    bind[9].is_null= &is_null[9];
                    bind[9].length= &length[9];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&lots_group;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* SHORT COLUMN */
                    bind[11].buffer_type= MYSQL_TYPE_LONG;
                    bind[11].buffer= (char *)&account_state;
                    bind[11].is_null= &is_null[11];
                    bind[11].length= &length[11];

                    /* STRING COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&parking_type;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* SHORT COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_STRING;
                    bind[13].buffer= (char *)addr;
                    bind[13].buffer_length= 100;
                    bind[13].is_null= &is_null[13];
                    length[13] = strlen(addr);
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_STRING;
                    bind[14].buffer= (char *)description;
                    bind[14].buffer_length= 100;
                    bind[14].is_null= &is_null[14];
                    length[14] = strlen(description);
                    bind[14].length= &length[14];

                    /* STRING COLUMN */
                    bind[15].buffer_type= MYSQL_TYPE_STRING;
                    bind[15].buffer= (char *)email;
                    bind[15].buffer_length= 64;
                    bind[15].is_null= &is_null[15];
                    length[15] = strlen(email);
                    bind[15].length= &length[15];

                    /* INTEGER COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_STRING;
                    bind[16].buffer= (char *)phone;
                    bind[16].buffer_length= 16;
                    bind[16].is_null= &is_null[16];
                    length[16] = strlen(phone);
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[17].buffer_type= MYSQL_TYPE_STRING;
                    bind[17].buffer= (char *)owner_name;
                    bind[17].buffer_length= 20;
                    bind[17].is_null= &is_null[17];
                    length[17] = strlen(owner_name);
                    bind[17].length= &length[17];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_STRING;
                    bind[18].buffer= (char *)hour_ticket_num;
                    bind[18].buffer_length= 20;
                    bind[18].is_null= &is_null[18];
                    length[18] = strlen(hour_ticket_num);
                    bind[18].length= &length[18];

                    /* SHORT COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&hour_ticket_type;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_LONG;
                    bind[20].buffer= (char *)&lot_id;
                    bind[20].is_null= &is_null[20];
                    bind[20].length= &length[20];

                    /* TIMESTAMP COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_STRING;
                    bind[21].buffer= (char *)online_member;
                    bind[21].buffer_length= 20;
                    bind[21].is_null= &is_null[21];
                    length[21] = strlen(online_member);
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&prepaid_charge_rule;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&monthly_charge_rule;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&ticket_lpbind;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&monthly_type;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[39].buffer_type= MYSQL_TYPE_LONG;
                    bind[39].buffer= (char *)&limit_time;
                    is_null[39] = (limit_time == -1);
                    bind[39].is_null= &is_null[39];
                    bind[39].length= &length[39];

                    /* VARCHAR COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_STRING;
                    bind[27].buffer= (char *)photo_id;
                    bind[27].buffer_length= 255;
                    bind[27].is_null= &is_null[27];
                    length[27] = strlen(photo_id);
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)add_info1;
                    bind[28].buffer_length= 255;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(add_info1);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_STRING;
                    bind[29].buffer= (char *)add_info2;
                    bind[29].buffer_length= 255;
                    bind[29].is_null= &is_null[29];
                    length[29] = strlen(add_info2);
                    bind[29].length= &length[29];

                    /* SHORT COLUMN */
                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&is_deleted;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    /* SHORT COLUMN */
                    bind[40].buffer_type= MYSQL_TYPE_LONG;
                    bind[40].buffer= (char *)&created_at;
                    bind[40].is_null= &is_null[40];
                    bind[40].length= &length[40];

                    /* SHORT COLUMN */
                    bind[32].buffer_type= MYSQL_TYPE_LONG;
                    bind[32].buffer= (char *)&created_by;
                    bind[32].is_null= &is_null[32];
                    bind[32].length= &length[32];

                    /* SHORT COLUMN */
                    bind[41].buffer_type= MYSQL_TYPE_LONG;
                    bind[41].buffer= (char *)&deleted_at;
                    is_null[41] = (deleted_at == -1);
                    bind[41].is_null= &is_null[41];
                    bind[41].length= &length[41];

                    /* SHORT COLUMN */
                    bind[34].buffer_type= MYSQL_TYPE_LONG;
                    bind[34].buffer= (char *)&deleted_by;
                    is_null[34] = (deleted_by == -1);
                    bind[34].is_null= &is_null[34];
                    bind[34].length= &length[34];

                    /* SHORT COLUMN */
                    bind[42].buffer_type= MYSQL_TYPE_LONG;
                    bind[42].buffer= (char *)&updated_at;
                    bind[42].is_null= &is_null[42];
                    bind[42].length= &length[42];

                    /* SHORT COLUMN */
                    bind[36].buffer_type= MYSQL_TYPE_LONG;
                    bind[36].buffer= (char *)&updated_by;
                    bind[36].is_null= &is_null[36];
                    bind[36].length= &length[36];
                }
                catch(...)
                {
                    return -3795;
                }
                
                try
                {
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3761;
                    }
                }
                catch(...)
                {
                    return -3761;
                }
                
                try
                {
                    if (mysql_stmt_store_result(stmt))
                    {
                      fprintf(stderr, " mysql_stmt_store_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3762;
                    }
                }
                catch(...)
                {
                    return -3762;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -3763;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -3764;
                }
                
            }
            else
            {
                return -3755;
            }
        }
        catch(...)
        {
            return -3755;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3764;
        }
        
    }
    else
    {
        return -3753;
    }
    //std::cout << "id = " << id <<std::endl;
    if(id == 0)
        return -1;
    return 0;
}

int accountInfo::Select_account_by_ID_park_lot_id(int index, int _park_lot_id)
{
    int id_;
    int park_lot_id_;
    std::string statment = "SELECT *,UNIX_TIMESTAMP(start_time),UNIX_TIMESTAMP(end_time),UNIX_TIMESTAMP(limit_time),UNIX_TIMESTAMP(created_at),UNIX_TIMESTAMP(deleted_at),UNIX_TIMESTAMP(updated_at) FROM account_info WHERE id=? and parking_lot_id = ?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3715;
            }
        }
        catch(...)
        {
            return -3715;
        }
        
        try
        {
            if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
            {
                try
                {
                    memset(bind_param, 0, sizeof(bind));
                    bind_param[0].buffer_type= MYSQL_TYPE_LONG;
                    bind_param[0].buffer= (char *)&id_;

                    bind_param[1].buffer_type= MYSQL_TYPE_LONG;
                    bind_param[1].buffer= (char *)&park_lot_id_;
                    if (mysql_stmt_bind_param(stmt, bind_param))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3417;
                    }
                    id_ = index;
                    park_lot_id_ = _park_lot_id;
                }
                catch(...)
                {
                    return -3417;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 2) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3418;
                    }
                }
                catch(...)
                {
                    return -3418;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3419;
                    }
                }
                catch(...)
                {
                    return -3419;
                }
                
                try
                {
                    int column_count= mysql_num_fields(prepare_meta_result);
                    std::cout << column_count << std::endl;
                    if (column_count != 43) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -3420;
                    }
                }
                catch(...)
                {
                    return -3420;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3421;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3421;
                }
                
                try
                {
                    memset(bind, 0, sizeof(bind));
                    memset(is_null,0,sizeof(is_null));
                    bind[0].buffer_type= MYSQL_TYPE_LONG;
                    bind[0].buffer= (char *)&id;
                    bind[0].is_null= &is_null[0];
                    bind[0].length= &length[0];

                    bind[1].buffer_type= MYSQL_TYPE_LONG;
                    bind[1].buffer= (char *)&parking_lot_id;
                    bind[1].is_null= &is_null[1];
                    bind[1].length= &length[1];

                    bind[2].buffer_type= MYSQL_TYPE_STRING;
                    bind[2].buffer= (char *)ticket;
                    bind[2].buffer_length= 20;
                    bind[2].is_null= &is_null[2];
                    length[2] = strlen(ticket);
                    bind[2].length= &length[2];

                    bind[3].buffer_type= MYSQL_TYPE_LONG;
                    bind[3].buffer= (char *)&ticket_type;
                    bind[3].is_null= &is_null[3];
                    bind[3].length= &length[3];

                    /* SHORT COLUMN */
                    bind[4].buffer_type= MYSQL_TYPE_STRING;
                    bind[4].buffer= (char *)plate;
                    bind[4].buffer_length= 12;
                    bind[4].is_null= &is_null[4];
                    length[4] = strlen(plate);
                    bind[4].length= &length[4];

                    /* SHORT COLUMN */
                    bind[37].buffer_type= MYSQL_TYPE_LONG;
                    bind[37].buffer= (char *)&start_time;
                    is_null[37] = (start_time == -1);
                    bind[37].is_null= &is_null[37];
                    bind[37].length= &length[37];

                    /* SHORT COLUMN */
                    bind[38].buffer_type= MYSQL_TYPE_LONG;
                    bind[38].buffer= (char *)&end_time;
                    is_null[38] = (end_time == -1);
                    bind[38].is_null= &is_null[38];
                    bind[38].length= &length[38];

                    /* SHORT COLUMN */
                    bind[7].buffer_type= MYSQL_TYPE_LONG;
                    bind[7].buffer= (char *)&access_group;
                    bind[7].is_null= &is_null[7];
                    bind[7].length= &length[7];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inner_group;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[9].buffer_type= MYSQL_TYPE_LONG;
                    bind[9].buffer= (char *)&time_group;
                    bind[9].is_null= &is_null[9];
                    bind[9].length= &length[9];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&lots_group;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* SHORT COLUMN */
                    bind[11].buffer_type= MYSQL_TYPE_LONG;
                    bind[11].buffer= (char *)&account_state;
                    bind[11].is_null= &is_null[11];
                    bind[11].length= &length[11];

                    /* STRING COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&parking_type;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* SHORT COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_STRING;
                    bind[13].buffer= (char *)addr;
                    bind[13].buffer_length= 100;
                    bind[13].is_null= &is_null[13];
                    length[13] = strlen(addr);
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_STRING;
                    bind[14].buffer= (char *)description;
                    bind[14].buffer_length= 100;
                    bind[14].is_null= &is_null[14];
                    length[14] = strlen(description);
                    bind[14].length= &length[14];

                    /* STRING COLUMN */
                    bind[15].buffer_type= MYSQL_TYPE_STRING;
                    bind[15].buffer= (char *)email;
                    bind[15].buffer_length= 64;
                    bind[15].is_null= &is_null[15];
                    length[15] = strlen(email);
                    bind[15].length= &length[15];

                    /* INTEGER COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_STRING;
                    bind[16].buffer= (char *)phone;
                    bind[16].buffer_length= 16;
                    bind[16].is_null= &is_null[16];
                    length[16] = strlen(phone);
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[17].buffer_type= MYSQL_TYPE_STRING;
                    bind[17].buffer= (char *)owner_name;
                    bind[17].buffer_length= 20;
                    bind[17].is_null= &is_null[17];
                    length[17] = strlen(owner_name);
                    bind[17].length= &length[17];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_STRING;
                    bind[18].buffer= (char *)hour_ticket_num;
                    bind[18].buffer_length= 20;
                    bind[18].is_null= &is_null[18];
                    length[18] = strlen(hour_ticket_num);
                    bind[18].length= &length[18];

                    /* SHORT COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&hour_ticket_type;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_LONG;
                    bind[20].buffer= (char *)&lot_id;
                    bind[20].is_null= &is_null[20];
                    bind[20].length= &length[20];

                    /* TIMESTAMP COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_STRING;
                    bind[21].buffer= (char *)online_member;
                    bind[21].buffer_length= 20;
                    bind[21].is_null= &is_null[21];
                    length[21] = strlen(online_member);
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&prepaid_charge_rule;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&monthly_charge_rule;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&ticket_lpbind;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&monthly_type;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[39].buffer_type= MYSQL_TYPE_LONG;
                    bind[39].buffer= (char *)&limit_time;
                    is_null[39] = (limit_time == -1);
                    bind[39].is_null= &is_null[39];
                    bind[39].length= &length[39];

                    /* VARCHAR COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_STRING;
                    bind[27].buffer= (char *)photo_id;
                    bind[27].buffer_length= 255;
                    bind[27].is_null= &is_null[27];
                    length[27] = strlen(photo_id);
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)add_info1;
                    bind[28].buffer_length= 255;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(add_info1);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_STRING;
                    bind[29].buffer= (char *)add_info2;
                    bind[29].buffer_length= 255;
                    bind[29].is_null= &is_null[29];
                    length[29] = strlen(add_info2);
                    bind[29].length= &length[29];

                    /* SHORT COLUMN */
                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&is_deleted;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    /* SHORT COLUMN */
                    bind[40].buffer_type= MYSQL_TYPE_LONG;
                    bind[40].buffer= (char *)&created_at;
                    bind[40].is_null= &is_null[40];
                    bind[40].length= &length[40];

                    /* SHORT COLUMN */
                    bind[32].buffer_type= MYSQL_TYPE_LONG;
                    bind[32].buffer= (char *)&created_by;
                    bind[32].is_null= &is_null[32];
                    bind[32].length= &length[32];

                    /* SHORT COLUMN */
                    bind[41].buffer_type= MYSQL_TYPE_LONG;
                    bind[41].buffer= (char *)&deleted_at;
                    is_null[41] = (deleted_at == -1);
                    bind[41].is_null= &is_null[41];
                    bind[41].length= &length[41];

                    /* SHORT COLUMN */
                    bind[34].buffer_type= MYSQL_TYPE_LONG;
                    bind[34].buffer= (char *)&deleted_by;
                    is_null[34] = (deleted_by == -1);
                    bind[34].is_null= &is_null[34];
                    bind[34].length= &length[34];

                    /* SHORT COLUMN */
                    bind[42].buffer_type= MYSQL_TYPE_LONG;
                    bind[42].buffer= (char *)&updated_at;
                    bind[42].is_null= &is_null[42];
                    bind[42].length= &length[42];

                    /* SHORT COLUMN */
                    bind[36].buffer_type= MYSQL_TYPE_LONG;
                    bind[36].buffer= (char *)&updated_by;
                    bind[36].is_null= &is_null[36];
                    bind[36].length= &length[36];
                }
                catch(...)
                {
                    return -3796;
                }
                
                try
                {
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3722;
                    }
                }
                catch(...)
                {
                    return -3722;
                }
                
                try
                {
                    if (mysql_stmt_store_result(stmt))
                    {
                      fprintf(stderr, " mysql_stmt_store_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3723;
                    }
                }
                catch(...)
                {
                    return -3723;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -3724;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -3725;
                }
                
            }
            else
            {
                return -3416;
            }
        }
        catch(...)
        {
            return -3416;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3726;
        }
        
    }
    else
    {
        return -3714;
    }
    if(id == 0)
        return -1;
    return 0;
}

int accountInfo::Select_account_by_ticket_park_lot_id(std::string _ticket, int _park_lot_id)
{
    char ticket_[20];
    int park_lot_id_;
    std::string statment = "SELECT *,UNIX_TIMESTAMP(start_time),UNIX_TIMESTAMP(end_time),UNIX_TIMESTAMP(limit_time),UNIX_TIMESTAMP(created_at),UNIX_TIMESTAMP(deleted_at),UNIX_TIMESTAMP(updated_at) FROM account_info WHERE ticket=? and parking_lot_id = ?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3741;
            }
        }
        catch(...)
        {
            return -3741;
        }
        
        try
        {
            if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
            {
                try
                {
                    memset(bind_param, 0, sizeof(bind));
                    bind_param[0].buffer_type= MYSQL_TYPE_STRING;
                    bind_param[0].buffer= (char *)ticket_;
                    bind_param[0].buffer_length= strlen(_ticket.c_str());

                    bind_param[1].buffer_type= MYSQL_TYPE_LONG;
                    bind_param[1].buffer= (char *)&park_lot_id_;

                    if (mysql_stmt_bind_param(stmt, bind_param))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3743;
                    }
                    strcpy( ticket_, _ticket.c_str());
                    park_lot_id_ = _park_lot_id;
                }
                catch(...)
                {
                    return -3743;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 2) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3744;
                    }
                }
                catch(...)
                {
                    return -3744;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3745;
                    }
                }
                catch(...)
                {
                    return -3745;
                }
                
                try
                {
                    int column_count= mysql_num_fields(prepare_meta_result);
                    //std::cout << column_count << std::endl;
                    if (column_count != 43) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -3746;
                    }
                }
                catch(...)
                {
                    return -3746;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3747;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3747;
                }
                
                try
                {
                    memset(bind, 0, sizeof(bind));
                    memset(is_null,0,sizeof(is_null));
                    bind[0].buffer_type= MYSQL_TYPE_LONG;
                    bind[0].buffer= (char *)&id;
                    bind[0].is_null= &is_null[0];
                    bind[0].length= &length[0];

                    bind[1].buffer_type= MYSQL_TYPE_LONG;
                    bind[1].buffer= (char *)&parking_lot_id;
                    bind[1].is_null= &is_null[1];
                    bind[1].length= &length[1];

                    bind[2].buffer_type= MYSQL_TYPE_STRING;
                    bind[2].buffer= (char *)ticket;
                    bind[2].buffer_length= 20;
                    bind[2].is_null= &is_null[2];
                    length[2] = strlen(ticket);
                    bind[2].length= &length[2];

                    bind[3].buffer_type= MYSQL_TYPE_LONG;
                    bind[3].buffer= (char *)&ticket_type;
                    bind[3].is_null= &is_null[3];
                    bind[3].length= &length[3];

                    /* SHORT COLUMN */
                    bind[4].buffer_type= MYSQL_TYPE_STRING;
                    bind[4].buffer= (char *)plate;
                    bind[4].buffer_length= 12;
                    bind[4].is_null= &is_null[4];
                    length[4] = strlen(plate);
                    bind[4].length= &length[4];

                    /* SHORT COLUMN */
                    bind[37].buffer_type= MYSQL_TYPE_LONG;
                    bind[37].buffer= (char *)&start_time;
                    is_null[37] = (start_time == -1);
                    bind[37].is_null= &is_null[37];
                    bind[37].length= &length[37];

                    /* SHORT COLUMN */
                    bind[38].buffer_type= MYSQL_TYPE_LONG;
                    bind[38].buffer= (char *)&end_time;
                    is_null[38] = (end_time == -1);
                    bind[38].is_null= &is_null[38];
                    bind[38].length= &length[38];

                    /* SHORT COLUMN */
                    bind[7].buffer_type= MYSQL_TYPE_LONG;
                    bind[7].buffer= (char *)&access_group;
                    bind[7].is_null= &is_null[7];
                    bind[7].length= &length[7];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inner_group;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[9].buffer_type= MYSQL_TYPE_LONG;
                    bind[9].buffer= (char *)&time_group;
                    bind[9].is_null= &is_null[9];
                    bind[9].length= &length[9];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&lots_group;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* SHORT COLUMN */
                    bind[11].buffer_type= MYSQL_TYPE_LONG;
                    bind[11].buffer= (char *)&account_state;
                    bind[11].is_null= &is_null[11];
                    bind[11].length= &length[11];

                    /* STRING COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&parking_type;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* SHORT COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_STRING;
                    bind[13].buffer= (char *)addr;
                    bind[13].buffer_length= 100;
                    bind[13].is_null= &is_null[13];
                    length[13] = strlen(addr);
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_STRING;
                    bind[14].buffer= (char *)description;
                    bind[14].buffer_length= 100;
                    bind[14].is_null= &is_null[14];
                    length[14] = strlen(description);
                    bind[14].length= &length[14];

                    /* STRING COLUMN */
                    bind[15].buffer_type= MYSQL_TYPE_STRING;
                    bind[15].buffer= (char *)email;
                    bind[15].buffer_length= 64;
                    bind[15].is_null= &is_null[15];
                    length[15] = strlen(email);
                    bind[15].length= &length[15];

                    /* INTEGER COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_STRING;
                    bind[16].buffer= (char *)phone;
                    bind[16].buffer_length= 16;
                    bind[16].is_null= &is_null[16];
                    length[16] = strlen(phone);
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[17].buffer_type= MYSQL_TYPE_STRING;
                    bind[17].buffer= (char *)owner_name;
                    bind[17].buffer_length= 20;
                    bind[17].is_null= &is_null[17];
                    length[17] = strlen(owner_name);
                    bind[17].length= &length[17];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_STRING;
                    bind[18].buffer= (char *)hour_ticket_num;
                    bind[18].buffer_length= 20;
                    bind[18].is_null= &is_null[18];
                    length[18] = strlen(hour_ticket_num);
                    bind[18].length= &length[18];

                    /* SHORT COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&hour_ticket_type;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_LONG;
                    bind[20].buffer= (char *)&lot_id;
                    bind[20].is_null= &is_null[20];
                    bind[20].length= &length[20];

                    /* TIMESTAMP COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_STRING;
                    bind[21].buffer= (char *)online_member;
                    bind[21].buffer_length= 20;
                    bind[21].is_null= &is_null[21];
                    length[21] = strlen(online_member);
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&prepaid_charge_rule;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&monthly_charge_rule;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&ticket_lpbind;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&monthly_type;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[39].buffer_type= MYSQL_TYPE_LONG;
                    bind[39].buffer= (char *)&limit_time;
                    is_null[39] = (limit_time == -1);
                    bind[39].is_null= &is_null[39];
                    bind[39].length= &length[39];

                    /* VARCHAR COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_STRING;
                    bind[27].buffer= (char *)photo_id;
                    bind[27].buffer_length= 255;
                    bind[27].is_null= &is_null[27];
                    length[27] = strlen(photo_id);
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)add_info1;
                    bind[28].buffer_length= 255;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(add_info1);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_STRING;
                    bind[29].buffer= (char *)add_info2;
                    bind[29].buffer_length= 255;
                    bind[29].is_null= &is_null[29];
                    length[29] = strlen(add_info2);
                    bind[29].length= &length[29];

                    /* SHORT COLUMN */
                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&is_deleted;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    /* SHORT COLUMN */
                    bind[40].buffer_type= MYSQL_TYPE_LONG;
                    bind[40].buffer= (char *)&created_at;
                    bind[40].is_null= &is_null[40];
                    bind[40].length= &length[40];

                    /* SHORT COLUMN */
                    bind[32].buffer_type= MYSQL_TYPE_LONG;
                    bind[32].buffer= (char *)&created_by;
                    bind[32].is_null= &is_null[32];
                    bind[32].length= &length[32];

                    /* SHORT COLUMN */
                    bind[41].buffer_type= MYSQL_TYPE_LONG;
                    bind[41].buffer= (char *)&deleted_at;
                    is_null[41] = (deleted_at == -1);
                    bind[41].is_null= &is_null[41];
                    bind[41].length= &length[41];

                    /* SHORT COLUMN */
                    bind[34].buffer_type= MYSQL_TYPE_LONG;
                    bind[34].buffer= (char *)&deleted_by;
                    is_null[34] = (deleted_by == -1);
                    bind[34].is_null= &is_null[34];
                    bind[34].length= &length[34];

                    /* SHORT COLUMN */
                    bind[42].buffer_type= MYSQL_TYPE_LONG;
                    bind[42].buffer= (char *)&updated_at;
                    bind[42].is_null= &is_null[42];
                    bind[42].length= &length[42];

                    /* SHORT COLUMN */
                    bind[36].buffer_type= MYSQL_TYPE_LONG;
                    bind[36].buffer= (char *)&updated_by;
                    bind[36].is_null= &is_null[36];
                    bind[36].length= &length[36];
                }
                catch(...)
                {
                    return -3795;
                }
                
                try
                {
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3748;
                    }
                }
                catch(...)
                {
                    return -3748;
                }
                
                try
                {
                    if (mysql_stmt_store_result(stmt))
                    {
                      fprintf(stderr, " mysql_stmt_store_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3749;
                    }
                }
                catch(...)
                {
                    return -3749;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -3750;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -3751;
                }
                
            }
            else
            {
                return -3742;
            }
        }
        catch(...)
        {
            return -3742;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3752;
        }
        
    }
    else
    {
        return -3740;
    }
    if(id == 0)
        return -1;
    //std::cout << id << std::endl;
    return 0;
}

int accountInfo::Select_account_by_plate_park_lot_id(std::string curr_plate, int match_plate, int _park_lot_id)
{
    char plate_[12];
    int park_lot_id_;
    std::string statment = "SELECT *,UNIX_TIMESTAMP(start_time),UNIX_TIMESTAMP(end_time),UNIX_TIMESTAMP(limit_time),UNIX_TIMESTAMP(created_at),UNIX_TIMESTAMP(deleted_at),UNIX_TIMESTAMP(updated_at) FROM account_info WHERE SUBSTR(plate,1," + std::to_string(match_plate) +")=? and parking_lot_id = ?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3768;
            }
        }
        catch(...)
        {
            return -3768;
        }
        
        try
        {
            if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
            {
                try
                {
                    memset(bind_param, 0, sizeof(bind));
                    bind_param[0].buffer_type= MYSQL_TYPE_STRING;
                    bind_param[0].buffer= (char *)plate_;
                    bind_param[0].buffer_length= strlen(curr_plate.c_str());

                    bind_param[1].buffer_type= MYSQL_TYPE_LONG;
                    bind_param[1].buffer= (char *)&park_lot_id_;

                    if (mysql_stmt_bind_param(stmt, bind_param))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3769;
                    }
                    strncpy( plate_, curr_plate.c_str(), match_plate);
                    park_lot_id_ = _park_lot_id;
                }
                catch(...)
                {
                    return -3769;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 2) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3770;
                    }
                }
                catch(...)
                {
                    return -3770;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3771;
                    }
                }
                catch(...)
                {
                    return -3771;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3771;
                    }
                }
                catch(...)
                {
                    return -3771;
                }
                
                try
                {
                    int column_count= mysql_num_fields(prepare_meta_result);
                    if (column_count != 43) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -3772;
                    }
                }
                catch(...)
                {
                    return -3772;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3773;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3773;
                }
                
                try
                {
                    memset(bind, 0, sizeof(bind));
                    memset(is_null,0,sizeof(is_null));
                    bind[0].buffer_type= MYSQL_TYPE_LONG;
                    bind[0].buffer= (char *)&id;
                    bind[0].is_null= &is_null[0];
                    bind[0].length= &length[0];

                    bind[1].buffer_type= MYSQL_TYPE_LONG;
                    bind[1].buffer= (char *)&parking_lot_id;
                    bind[1].is_null= &is_null[1];
                    bind[1].length= &length[1];

                    bind[2].buffer_type= MYSQL_TYPE_STRING;
                    bind[2].buffer= (char *)ticket;
                    bind[2].buffer_length= 20;
                    bind[2].is_null= &is_null[2];
                    length[2] = strlen(ticket);
                    bind[2].length= &length[2];

                    bind[3].buffer_type= MYSQL_TYPE_LONG;
                    bind[3].buffer= (char *)&ticket_type;
                    bind[3].is_null= &is_null[3];
                    bind[3].length= &length[3];

                    /* SHORT COLUMN */
                    bind[4].buffer_type= MYSQL_TYPE_STRING;
                    bind[4].buffer= (char *)plate;
                    bind[4].buffer_length= 12;
                    bind[4].is_null= &is_null[4];
                    length[4] = strlen(plate);
                    bind[4].length= &length[4];

                    /* SHORT COLUMN */
                    bind[37].buffer_type= MYSQL_TYPE_LONG;
                    bind[37].buffer= (char *)&start_time;
                    is_null[37] = (start_time == -1);
                    bind[37].is_null= &is_null[37];
                    bind[37].length= &length[37];

                    /* SHORT COLUMN */
                    bind[38].buffer_type= MYSQL_TYPE_LONG;
                    bind[38].buffer= (char *)&end_time;
                    is_null[38] = (end_time == -1);
                    bind[38].is_null= &is_null[38];
                    bind[38].length= &length[38];

                    /* SHORT COLUMN */
                    bind[7].buffer_type= MYSQL_TYPE_LONG;
                    bind[7].buffer= (char *)&access_group;
                    bind[7].is_null= &is_null[7];
                    bind[7].length= &length[7];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inner_group;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[9].buffer_type= MYSQL_TYPE_LONG;
                    bind[9].buffer= (char *)&time_group;
                    bind[9].is_null= &is_null[9];
                    bind[9].length= &length[9];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&lots_group;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* SHORT COLUMN */
                    bind[11].buffer_type= MYSQL_TYPE_LONG;
                    bind[11].buffer= (char *)&account_state;
                    bind[11].is_null= &is_null[11];
                    bind[11].length= &length[11];

                    /* STRING COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&parking_type;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* SHORT COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_STRING;
                    bind[13].buffer= (char *)addr;
                    bind[13].buffer_length= 100;
                    bind[13].is_null= &is_null[13];
                    length[13] = strlen(addr);
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_STRING;
                    bind[14].buffer= (char *)description;
                    bind[14].buffer_length= 100;
                    bind[14].is_null= &is_null[14];
                    length[14] = strlen(description);
                    bind[14].length= &length[14];

                    /* STRING COLUMN */
                    bind[15].buffer_type= MYSQL_TYPE_STRING;
                    bind[15].buffer= (char *)email;
                    bind[15].buffer_length= 64;
                    bind[15].is_null= &is_null[15];
                    length[15] = strlen(email);
                    bind[15].length= &length[15];

                    /* INTEGER COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_STRING;
                    bind[16].buffer= (char *)phone;
                    bind[16].buffer_length= 16;
                    bind[16].is_null= &is_null[16];
                    length[16] = strlen(phone);
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[17].buffer_type= MYSQL_TYPE_STRING;
                    bind[17].buffer= (char *)owner_name;
                    bind[17].buffer_length= 20;
                    bind[17].is_null= &is_null[17];
                    length[17] = strlen(owner_name);
                    bind[17].length= &length[17];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_STRING;
                    bind[18].buffer= (char *)hour_ticket_num;
                    bind[18].buffer_length= 20;
                    bind[18].is_null= &is_null[18];
                    length[18] = strlen(hour_ticket_num);
                    bind[18].length= &length[18];

                    /* SHORT COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&hour_ticket_type;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_LONG;
                    bind[20].buffer= (char *)&lot_id;
                    bind[20].is_null= &is_null[20];
                    bind[20].length= &length[20];

                    /* TIMESTAMP COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_STRING;
                    bind[21].buffer= (char *)online_member;
                    bind[21].buffer_length= 20;
                    bind[21].is_null= &is_null[21];
                    length[21] = strlen(online_member);
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&prepaid_charge_rule;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&monthly_charge_rule;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&ticket_lpbind;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&monthly_type;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[39].buffer_type= MYSQL_TYPE_LONG;
                    bind[39].buffer= (char *)&limit_time;
                    is_null[39] = (limit_time == -1);
                    bind[39].is_null= &is_null[39];
                    bind[39].length= &length[39];

                    /* VARCHAR COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_STRING;
                    bind[27].buffer= (char *)photo_id;
                    bind[27].buffer_length= 255;
                    bind[27].is_null= &is_null[27];
                    length[27] = strlen(photo_id);
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)add_info1;
                    bind[28].buffer_length= 255;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(add_info1);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_STRING;
                    bind[29].buffer= (char *)add_info2;
                    bind[29].buffer_length= 255;
                    bind[29].is_null= &is_null[29];
                    length[29] = strlen(add_info2);
                    bind[29].length= &length[29];

                    /* SHORT COLUMN */
                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&is_deleted;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    /* SHORT COLUMN */
                    bind[40].buffer_type= MYSQL_TYPE_LONG;
                    bind[40].buffer= (char *)&created_at;
                    bind[40].is_null= &is_null[40];
                    bind[40].length= &length[40];

                    /* SHORT COLUMN */
                    bind[32].buffer_type= MYSQL_TYPE_LONG;
                    bind[32].buffer= (char *)&created_by;
                    bind[32].is_null= &is_null[32];
                    bind[32].length= &length[32];

                    /* SHORT COLUMN */
                    bind[41].buffer_type= MYSQL_TYPE_LONG;
                    bind[41].buffer= (char *)&deleted_at;
                    is_null[41] = (deleted_at == -1);
                    bind[41].is_null= &is_null[41];
                    bind[41].length= &length[41];

                    /* SHORT COLUMN */
                    bind[34].buffer_type= MYSQL_TYPE_LONG;
                    bind[34].buffer= (char *)&deleted_by;
                    is_null[34] = (deleted_by == -1);
                    bind[34].is_null= &is_null[34];
                    bind[34].length= &length[34];

                    /* SHORT COLUMN */
                    bind[42].buffer_type= MYSQL_TYPE_LONG;
                    bind[42].buffer= (char *)&updated_at;
                    bind[42].is_null= &is_null[42];
                    bind[42].length= &length[42];

                    /* SHORT COLUMN */
                    bind[36].buffer_type= MYSQL_TYPE_LONG;
                    bind[36].buffer= (char *)&updated_by;
                    bind[36].is_null= &is_null[36];
                    bind[36].length= &length[36];
                }
                catch(...)
                {
                    return -3795;
                }
                
                try
                {
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3774;
                    }
                }
                catch(...)
                {
                    return -3774;
                }
                
                try
                {
                    if (mysql_stmt_store_result(stmt))
                    {
                      fprintf(stderr, " mysql_stmt_store_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3775;
                    }
                }
                catch(...)
                {
                    return -3775;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -3776;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -3777;
                }
                
            }
            else
            {
                return -3769;
            }
        }
        catch(...)
        {
            return -3769;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3778;
        }
        
    }
    else
    {
        return -3766;
    }
    //std::cout << "id = " << id <<std::endl;
    if(id == 0)
        return -1;
    return 0;
}

int accountInfo::Delete_accountInfo()
{
    try
    {
        parking_lot_id = 0;
        strcpy(ticket, "");
        ticket_type = 0;
        strcpy(plate, "");
        start_time = -1;
        end_time = -1;
        access_group = 255;
        inner_group = 255;
        time_group = 255;
        lots_group = 65535;
        account_state = 0;
        parking_type = 0;
        strcpy(addr, "");
        strcpy(description, "");
        strcpy(email, "");
        strcpy(phone, "");
        strcpy(owner_name, "");
        strcpy(hour_ticket_num, "");
        hour_ticket_type = 0;
        lot_id = 0;
        strcpy(online_member, "");
        prepaid_charge_rule = 0;
        monthly_charge_rule = 0;
        ticket_lpbind = 0;
        monthly_type = 255;
        limit_time = -1;
        strcpy(photo_id, "");
        strcpy(add_info1, "");
        strcpy(add_info2, "");
        is_deleted = 0;
        created_at = -1;
        created_by = 0;
        deleted_at = -1;
        deleted_by = 0;
        updated_at = -1;
        updated_by = 0; 
    }
    catch(...)
    {
        return -3798;
    }
    
    
    std::string statment = "DELETE FROM `account_info` WHERE `id`= ?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3788;
            }
        }
        catch(...)
        {
            return -3788;
        }
        
        try
        {
            if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
            {
                try
                {
                    memset(bind_param, 0, sizeof(bind));
                    bind_param[0].buffer_type= MYSQL_TYPE_LONG;
                    bind_param[0].buffer= (char *)&id;

                    if (mysql_stmt_bind_param(stmt, bind_param))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3790;
                    }
                }
                catch(...)
                {
                    return -3790;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 1) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3791;
                    }
                }
                catch(...)
                {
                    return -3791;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3792;
                    }
                    if (mysql_stmt_affected_rows(stmt) != 1)
                    {
                        return -3792;
                    }  
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3792;
                }
                  
            }
            else
            {
                return -3789;
            }
        }
        catch(...)
        {
            return -3789;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3793;
        }
        
    }
    else
    {
        return -3787;
    }
    id = 0;
    return 0;
}

int accountInfo::print_account_info_variables()
{
    try
    {
        std::cout << "id = " << id << std::endl;
        std::cout << "parking_lot_id = " <<parking_lot_id << std::endl;
        std::cout << "ticket = " <<ticket << std::endl;
        std::cout << "ticket_type = " <<ticket_type << std::endl;
        std::cout << "plate = " <<plate << std::endl;
        std::cout << "start_time = " <<Print_time(start_time) << std::endl;
        std::cout << "end_time = " <<Print_time(end_time) << std::endl;
        std::cout << "access_group = " <<access_group << std::endl;
        std::cout << "inner_group = " <<inner_group << std::endl;
        std::cout << "time_group = " <<time_group << std::endl;
        std::cout << "lots_group = " <<lots_group << std::endl;
        std::cout << "account_state = " <<account_state << std::endl;
        std::cout << "parking_type = " <<parking_type << std::endl;
        std::cout << "addr = " <<addr << std::endl;
        std::cout << "description = " <<description<< std::endl;
        std::cout << "email = " <<email<< std::endl;
        std::cout << "phone = " <<phone<< std::endl;
        std::cout << "owner_name = " <<owner_name<< std::endl;
        std::cout << "hour_ticket_num = " <<hour_ticket_num<< std::endl;
        std::cout << "hour_ticket_type = " <<hour_ticket_type<< std::endl;
        std::cout << "lot_id = " <<lot_id<< std::endl;
        std::cout << "online_member = " <<online_member<< std::endl;
        std::cout << "prepaid_charge_rule = " <<prepaid_charge_rule<< std::endl;
        std::cout << "monthly_charge_rule = " <<monthly_charge_rule<< std::endl;
        std::cout << "ticket_lpbind = " <<ticket_lpbind<< std::endl;
        std::cout << "monthly_type = " <<monthly_type<< std::endl;
        std::cout << "limit_time = " <<Print_time(limit_time) << std::endl;
        std::cout << "photo_id = " <<photo_id<< std::endl;
        std::cout << "add_info1 = " <<add_info1<< std::endl;
        std::cout << "add_info2 = " <<add_info2<< std::endl;
        std::cout << "is_deleted = " <<is_deleted<< std::endl;
        std::cout << "created_at = " <<Print_time(created_at) << std::endl;
        std::cout << "created_by = " <<created_by << std::endl;
        std::cout << "deleted_at = " <<Print_time(deleted_at) << std::endl;
        std::cout << "deleted_by = " <<deleted_by << std::endl;
        std::cout << "updated_at = " <<Print_time(updated_at) << std::endl;
        std::cout << "updated_by = " <<updated_by << std::endl;
    }
    catch(...)
    {
        return -3794;
    }
    return 0;
}

