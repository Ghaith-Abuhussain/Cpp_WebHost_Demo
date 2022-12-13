#include "account_state.h"

account_state::account_state(MYSQL *_mysql)
{
    mysql = _mysql;
}

account_state::~account_state()
{
    
}

int account_state::Insert_update_account_state()
{
    std::string statment = "INSERT INTO `account_state` (`id` ,`parking_lot_id`,`ticket` ,`ticket_type` ,`plate` ,`parking_type`,`present_type`,`intime`,`inserial`,`outtime`,`outserial`,`pay_time`,`pay_serial`  ,`paid_sum` ,`charge_type`,`inner_intime`,`inner_inserial`  ,`inner_outtime`,`inner_outserial` ,`limit_sum`,`online_order`,`insite`,`charge_site`,`inner_insite`,`inner_outsite`,`prepaid_balance`,`l2_id`,`prepaid_account_id`,`hour_ticket_num`  ,`hour_ticket_type`,`total_sum`,`is_deleted`,`created_at` ,`created_by` ,`deleted_at` ,`deleted_by` ,`updated_at` ,`updated_by`) VALUES ( ?, ?, ?, ?, ?, ?, ?, FROM_UNIXTIME(?), ?, FROM_UNIXTIME(?),?, FROM_UNIXTIME(?), ?,?, ?, FROM_UNIXTIME(?), ?, FROM_UNIXTIME(?),?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, FROM_UNIXTIME(?), ?,FROM_UNIXTIME(?),?,FROM_UNIXTIME(?),?) ON DUPLICATE KEY UPDATE id = VALUES(id),parking_lot_id= VALUES(parking_lot_id),ticket= VALUES(ticket),ticket_type= VALUES(ticket_type),plate= VALUES(plate),parking_type= VALUES(parking_type),present_type= VALUES(present_type),intime= VALUES(intime),inserial= VALUES(inserial),outtime= VALUES(outtime),outserial= VALUES(outserial),pay_time= VALUES(pay_time),pay_serial= VALUES(pay_serial),paid_sum= VALUES(paid_sum),charge_type= VALUES(charge_type),inner_intime= VALUES(inner_intime),inner_inserial= VALUES(inner_inserial),inner_outtime= VALUES(inner_outtime),inner_outserial= VALUES(inner_outserial),limit_sum= VALUES(limit_sum),online_order= VALUES(online_order),insite= VALUES(insite),charge_site= VALUES(charge_site),inner_insite= VALUES(inner_insite),inner_outsite= VALUES(inner_outsite),prepaid_balance= VALUES(prepaid_balance),l2_id= VALUES(l2_id),prepaid_account_id= VALUES(prepaid_account_id),hour_ticket_num= VALUES(hour_ticket_num),hour_ticket_type= VALUES(hour_ticket_type),total_sum= VALUES(total_sum),is_deleted= VALUES(is_deleted),created_at= VALUES(created_at),created_by= VALUES(created_by),deleted_at= VALUES(deleted_at),deleted_by= VALUES(deleted_by),updated_at= VALUES(updated_at),updated_by= VALUES(updated_by)";
    if (mysql != NULL) 
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3880;
            }
        }
        catch(...)
        {
            return -3880;
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
                    bind[5].buffer= (char *)&parking_type;
                    bind[5].is_null= &is_null[5];
                    bind[5].length= &length[5];

                    /* SHORT COLUMN */
                    bind[6].buffer_type= MYSQL_TYPE_LONG;
                    bind[6].buffer= (char *)&present_type;
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    /* SHORT COLUMN */
                    bind[7].buffer_type= MYSQL_TYPE_LONG;
                    bind[7].buffer= (char *)&intime;
                    is_null[7] = (intime == -1);
                    bind[7].is_null= &is_null[7];
                    bind[7].length= &length[7];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inserial;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[9].buffer_type= MYSQL_TYPE_LONG;
                    bind[9].buffer= (char *)&outtime;
                    is_null[9] = (outtime == -1);
                    bind[9].is_null= &is_null[9];
                    bind[9].length= &length[9];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&outserial;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* STRING COLUMN */
                    bind[11].buffer_type= MYSQL_TYPE_LONG;
                    bind[11].buffer= (char *)&pay_time;
                    is_null[11] = (pay_time == -1);
                    bind[11].is_null= &is_null[11];
                    bind[11].length= &length[11];

                    /* SHORT COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&pay_serial;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* STRING COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_LONG;
                    bind[13].buffer= (char *)&paid_sum;
                    bind[13].is_null= &is_null[13];
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_LONG;
                    bind[14].buffer= (char *)&charge_type;
                    bind[14].is_null= &is_null[14];
                    bind[14].length= &length[14];

                    /* INTEGER COLUMN */
                    bind[15].buffer_type= MYSQL_TYPE_LONG;
                    bind[15].buffer= (char *)&inner_intime;
                    is_null[15] = (inner_intime == -1);
                    bind[15].is_null= &is_null[15];
                    bind[15].length= &length[15];

                    /* SHORT COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_LONG;
                    bind[16].buffer= (char *)&inner_inserial;
                    bind[16].is_null= &is_null[16];
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[17].buffer_type= MYSQL_TYPE_LONG;
                    bind[17].buffer= (char *)&inner_outtime;
                    is_null[17] = (inner_outtime == -1);
                    bind[17].is_null= &is_null[17];
                    bind[17].length= &length[17];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_LONG;
                    bind[18].buffer= (char *)&inner_outserial;
                    bind[18].is_null= &is_null[18];
                    bind[18].length= &length[18];

                    /* TIMESTAMP COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&limit_sum;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_STRING;
                    bind[20].buffer= (char *)online_order;
                    bind[20].buffer_length= 255;
                    bind[20].is_null= &is_null[20];
                    length[20] = strlen(online_order);
                    bind[20].length= &length[20];

                    /* SHORT COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_LONG;
                    bind[21].buffer= (char *)&insite;
                    bind[21].is_null= &is_null[21];
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&charge_site;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&inner_insite;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&inner_outsite;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&prepaid_balance;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[26].buffer_type= MYSQL_TYPE_LONG;
                    bind[26].buffer= (char *)&l2_id;
                    bind[26].is_null= &is_null[26];
                    bind[26].length= &length[26];

                    /* SHORT COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_LONG;
                    bind[27].buffer= (char *)&prepaid_account_id;
                    bind[27].is_null= &is_null[27];
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)hour_ticket_num;
                    bind[28].buffer_length= 20;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(hour_ticket_num);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_LONG;
                    bind[29].buffer= (char *)&hour_ticket_type;
                    bind[29].is_null= &is_null[29];
                    bind[29].length= &length[29];

                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&total_sum;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    bind[31].buffer_type= MYSQL_TYPE_LONG;
                    bind[31].buffer= (char *)&is_deleted;
                    bind[31].is_null= &is_null[31];
                    bind[31].length= &length[31];

                    bind[32].buffer_type= MYSQL_TYPE_LONG;
                    bind[32].buffer= (char *)&created_at;
                    bind[32].is_null= &is_null[32];
                    bind[32].length= &length[32];

                    bind[33].buffer_type= MYSQL_TYPE_LONG;
                    bind[33].buffer= (char *)&created_by;
                    bind[33].is_null= &is_null[33];
                    bind[33].length= &length[33];

                    bind[34].buffer_type= MYSQL_TYPE_LONG;
                    bind[34].buffer= (char *)&deleted_at;
                    is_null[34] = (deleted_at == -1);
                    bind[34].is_null= &is_null[34];
                    bind[34].length= &length[34];

                    bind[35].buffer_type= MYSQL_TYPE_LONG;
                    bind[35].buffer= (char *)&deleted_by;
                    is_null[35] = (deleted_by == -1);
                    bind[35].is_null= &is_null[35];
                    bind[35].length= &length[35];

                    bind[36].buffer_type= MYSQL_TYPE_LONG;
                    bind[36].buffer= (char *)&updated_at;
                    bind[36].is_null= &is_null[36];
                    bind[36].length= &length[36];

                    bind[37].buffer_type= MYSQL_TYPE_LONG;
                    bind[37].buffer= (char *)&updated_by;
                    bind[37].is_null= &is_null[37];
                bind[37].length= &length[37];
                }
                catch(...)
                {
                    return -3897;
                }
                
                try
                {
                    if (mysql_stmt_bind_param(stmt, bind))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3882;
                    }
                }
                catch(...)
                {
                    return -3882;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 38) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3883;
                    }
                }
                catch(...)
                {
                    return -3883;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3884;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3884;
                }
                
                try
                {
                    if (mysql_stmt_affected_rows(stmt) == 1)
                    {
                        fprintf(stderr, "account state %d with %d inserted\n", parking_lot_id, id);
                    }
                    if (mysql_stmt_affected_rows(stmt) != 1)
                    {
                        fprintf(stderr, "account state %d with %d updated\n", parking_lot_id, id);
                    }
                }
                catch(...)
                {
                    return -3885;
                }
                
            }
            else
            {
                return -3881;
            }
        }
        catch(...)
        {
            return -3881;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3886;
        }
        
    }
    else
    {
        return -3879;
    }
    return 0;
}

int account_state::Select_account_state_by_ID(int index)
{
    int id_;
    std::string statment = "SELECT *,UNIX_TIMESTAMP(intime),UNIX_TIMESTAMP(outtime),UNIX_TIMESTAMP(pay_time),UNIX_TIMESTAMP(inner_intime),UNIX_TIMESTAMP(inner_outtime),UNIX_TIMESTAMP(created_at),UNIX_TIMESTAMP(deleted_at),UNIX_TIMESTAMP(updated_at) FROM account_state WHERE id=?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3802;
            }
        }
        catch(...)
        {
            return -3802;
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
                        return -3804;
                    }
                    id_ = index;
                }
                catch(...)
                {
                    return -3804;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 1) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3805;
                    }
                }
                catch(...)
                {
                    return -3805;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3806;
                    }
                }
                catch(...)
                {
                    return -3806;
                }
                
                try
                {
                    int column_count= mysql_num_fields(prepare_meta_result);
                    if (column_count != 46) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -3807;
                    }
                }
                catch(...)
                {
                    return -3807;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3808;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3808;
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
                    bind[5].buffer_type= MYSQL_TYPE_LONG;
                    bind[5].buffer= (char *)&parking_type;
                    bind[5].is_null= &is_null[5];
                    bind[5].length= &length[5];

                    /* SHORT COLUMN */
                    bind[6].buffer_type= MYSQL_TYPE_LONG;
                    bind[6].buffer= (char *)&present_type;
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    /* SHORT COLUMN */
                    bind[38].buffer_type= MYSQL_TYPE_LONG;
                    bind[38].buffer= (char *)&intime;
                    is_null[38] = (intime == -1);
                    bind[38].is_null= &is_null[38];
                    bind[38].length= &length[38];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inserial;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[39].buffer_type= MYSQL_TYPE_LONG;
                    bind[39].buffer= (char *)&outtime;
                    is_null[39] = (outtime == -1);
                    bind[39].is_null= &is_null[39];
                    bind[39].length= &length[39];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&outserial;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* STRING COLUMN */
                    bind[40].buffer_type= MYSQL_TYPE_LONG;
                    bind[40].buffer= (char *)&pay_time;
                    is_null[40] = (pay_time == -1);
                    bind[40].is_null= &is_null[40];
                    bind[40].length= &length[40];

                    /* SHORT COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&pay_serial;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* STRING COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_LONG;
                    bind[13].buffer= (char *)&paid_sum;
                    bind[13].is_null= &is_null[13];
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_LONG;
                    bind[14].buffer= (char *)&charge_type;
                    bind[14].is_null= &is_null[14];
                    bind[14].length= &length[14];

                    /* INTEGER COLUMN */
                    bind[41].buffer_type= MYSQL_TYPE_LONG;
                    bind[41].buffer= (char *)&inner_intime;
                    is_null[41] = (inner_intime == -1);
                    bind[41].is_null= &is_null[41];
                    bind[41].length= &length[41];

                    /* SHORT COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_LONG;
                    bind[16].buffer= (char *)&inner_inserial;
                    bind[16].is_null= &is_null[16];
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[42].buffer_type= MYSQL_TYPE_LONG;
                    bind[42].buffer= (char *)&inner_outtime;
                    is_null[42] = (inner_outtime == -1);
                    bind[42].is_null= &is_null[42];
                    bind[42].length= &length[42];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_LONG;
                    bind[18].buffer= (char *)&inner_outserial;
                    bind[18].is_null= &is_null[18];
                    bind[18].length= &length[18];

                    /* TIMESTAMP COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&limit_sum;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_STRING;
                    bind[20].buffer= (char *)online_order;
                    bind[20].buffer_length= 255;
                    bind[20].is_null= &is_null[20];
                    length[20] = strlen(online_order);
                    bind[20].length= &length[20];

                    /* SHORT COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_LONG;
                    bind[21].buffer= (char *)&insite;
                    bind[21].is_null= &is_null[21];
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&charge_site;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&inner_insite;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&inner_outsite;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&prepaid_balance;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[26].buffer_type= MYSQL_TYPE_LONG;
                    bind[26].buffer= (char *)&l2_id;
                    bind[26].is_null= &is_null[26];
                    bind[26].length= &length[26];

                    /* SHORT COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_LONG;
                    bind[27].buffer= (char *)&prepaid_account_id;
                    bind[27].is_null= &is_null[27];
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)hour_ticket_num;
                    bind[28].buffer_length= 20;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(hour_ticket_num);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_LONG;
                    bind[29].buffer= (char *)&hour_ticket_type;
                    bind[29].is_null= &is_null[29];
                    bind[29].length= &length[29];

                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&total_sum;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    bind[31].buffer_type= MYSQL_TYPE_LONG;
                    bind[31].buffer= (char *)&is_deleted;
                    bind[31].is_null= &is_null[31];
                    bind[31].length= &length[31];

                    bind[43].buffer_type= MYSQL_TYPE_LONG;
                    bind[43].buffer= (char *)&created_at;
                    bind[43].is_null= &is_null[43];
                    bind[43].length= &length[43];

                    bind[33].buffer_type= MYSQL_TYPE_LONG;
                    bind[33].buffer= (char *)&created_by;
                    bind[33].is_null= &is_null[33];
                    bind[33].length= &length[33];

                    bind[44].buffer_type= MYSQL_TYPE_LONG;
                    bind[44].buffer= (char *)&deleted_at;
                    is_null[44] = (deleted_at == -1);
                    bind[44].is_null= &is_null[44];
                    bind[44].length= &length[44];

                    bind[35].buffer_type= MYSQL_TYPE_LONG;
                    bind[35].buffer= (char *)&deleted_by;
                    is_null[35] = (deleted_by == -1);
                    bind[35].is_null= &is_null[35];
                    bind[35].length= &length[35];

                    bind[45].buffer_type= MYSQL_TYPE_LONG;
                    bind[45].buffer= (char *)&updated_at;
                    bind[45].is_null= &is_null[45];
                    bind[45].length= &length[45];

                    bind[37].buffer_type= MYSQL_TYPE_LONG;
                    bind[37].buffer= (char *)&updated_by;
                    bind[37].is_null= &is_null[37];
                    bind[37].length= &length[37];
                }
                catch(...)
                {
                    return -3895;
                }
                
                try
                {
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3809;
                    }
                }
                catch(...)
                {
                    return -3809;
                }
                
                try
                {
                    if (mysql_stmt_store_result(stmt))
                    {
                      fprintf(stderr, " mysql_stmt_store_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3810;
                    }
                }
                catch(...)
                {
                    return -3810;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -3811;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -3812;
                }
                
            }
            else
            {
                return -3803;
            }
        }
        catch(...)
        {
            return -3803;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3813;
        }
        
    }
    else
    {
        return -3801;
    }
    if(id == 0)
    {
        return -1;
    }
    return 0;
}

int account_state::Select_account_state_by_ticket(std::string _ticket)
{
    char ticket_[20];
    std::string statment = "SELECT *,UNIX_TIMESTAMP(intime),UNIX_TIMESTAMP(outtime),UNIX_TIMESTAMP(pay_time),UNIX_TIMESTAMP(inner_intime),UNIX_TIMESTAMP(inner_outtime),UNIX_TIMESTAMP(created_at),UNIX_TIMESTAMP(deleted_at),UNIX_TIMESTAMP(updated_at) FROM account_state WHERE ticket=?";
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
                        return -3830;
                    }
                    strcpy( ticket_, _ticket.c_str());
                }
                catch(...)
                {
                    return -3830;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 1) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3831;
                    }
                }
                catch(...)
                {
                    return -3831;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3832;
                    }
                }
                catch(...)
                {
                    return -3832;
                }
                
                try
                {
                    int column_count= mysql_num_fields(prepare_meta_result);
                    //std::cout << column_count << std::endl;
                    if (column_count != 46) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -3833;
                    }
                }
                catch(...)
                {
                    return -3833;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3834;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3834;
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
                    bind[5].buffer_type= MYSQL_TYPE_LONG;
                    bind[5].buffer= (char *)&parking_type;
                    bind[5].is_null= &is_null[5];
                    bind[5].length= &length[5];

                    /* SHORT COLUMN */
                    bind[6].buffer_type= MYSQL_TYPE_LONG;
                    bind[6].buffer= (char *)&present_type;
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    /* SHORT COLUMN */
                    bind[38].buffer_type= MYSQL_TYPE_LONG;
                    bind[38].buffer= (char *)&intime;
                    is_null[38] = (intime == -1);
                    bind[38].is_null= &is_null[38];
                    bind[38].length= &length[38];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inserial;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[39].buffer_type= MYSQL_TYPE_LONG;
                    bind[39].buffer= (char *)&outtime;
                    is_null[39] = (outtime == -1);
                    bind[39].is_null= &is_null[39];
                    bind[39].length= &length[39];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&outserial;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* STRING COLUMN */
                    bind[40].buffer_type= MYSQL_TYPE_LONG;
                    bind[40].buffer= (char *)&pay_time;
                    is_null[40] = (pay_time == -1);
                    bind[40].is_null= &is_null[40];
                    bind[40].length= &length[40];

                    /* SHORT COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&pay_serial;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* STRING COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_LONG;
                    bind[13].buffer= (char *)&paid_sum;
                    bind[13].is_null= &is_null[13];
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_LONG;
                    bind[14].buffer= (char *)&charge_type;
                    bind[14].is_null= &is_null[14];
                    bind[14].length= &length[14];

                    /* INTEGER COLUMN */
                    bind[41].buffer_type= MYSQL_TYPE_LONG;
                    bind[41].buffer= (char *)&inner_intime;
                    is_null[41] = (inner_intime == -1);
                    bind[41].is_null= &is_null[41];
                    bind[41].length= &length[41];

                    /* SHORT COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_LONG;
                    bind[16].buffer= (char *)&inner_inserial;
                    bind[16].is_null= &is_null[16];
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[42].buffer_type= MYSQL_TYPE_LONG;
                    bind[42].buffer= (char *)&inner_outtime;
                    is_null[42] = (inner_outtime == -1);
                    bind[42].is_null= &is_null[42];
                    bind[42].length= &length[42];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_LONG;
                    bind[18].buffer= (char *)&inner_outserial;
                    bind[18].is_null= &is_null[18];
                    bind[18].length= &length[18];

                    /* TIMESTAMP COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&limit_sum;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_STRING;
                    bind[20].buffer= (char *)online_order;
                    bind[20].buffer_length= 255;
                    bind[20].is_null= &is_null[20];
                    length[20] = strlen(online_order);
                    bind[20].length= &length[20];

                    /* SHORT COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_LONG;
                    bind[21].buffer= (char *)&insite;
                    bind[21].is_null= &is_null[21];
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&charge_site;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&inner_insite;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&inner_outsite;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&prepaid_balance;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[26].buffer_type= MYSQL_TYPE_LONG;
                    bind[26].buffer= (char *)&l2_id;
                    bind[26].is_null= &is_null[26];
                    bind[26].length= &length[26];

                    /* SHORT COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_LONG;
                    bind[27].buffer= (char *)&prepaid_account_id;
                    bind[27].is_null= &is_null[27];
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)hour_ticket_num;
                    bind[28].buffer_length= 20;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(hour_ticket_num);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_LONG;
                    bind[29].buffer= (char *)&hour_ticket_type;
                    bind[29].is_null= &is_null[29];
                    bind[29].length= &length[29];

                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&total_sum;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    bind[31].buffer_type= MYSQL_TYPE_LONG;
                    bind[31].buffer= (char *)&is_deleted;
                    bind[31].is_null= &is_null[31];
                    bind[31].length= &length[31];

                    bind[43].buffer_type= MYSQL_TYPE_LONG;
                    bind[43].buffer= (char *)&created_at;
                    bind[43].is_null= &is_null[43];
                    bind[43].length= &length[43];

                    bind[33].buffer_type= MYSQL_TYPE_LONG;
                    bind[33].buffer= (char *)&created_by;
                    bind[33].is_null= &is_null[33];
                    bind[33].length= &length[33];

                    bind[44].buffer_type= MYSQL_TYPE_LONG;
                    bind[44].buffer= (char *)&deleted_at;
                    is_null[44] = (deleted_at == -1);
                    bind[44].is_null= &is_null[44];
                    bind[44].length= &length[44];

                    bind[35].buffer_type= MYSQL_TYPE_LONG;
                    bind[35].buffer= (char *)&deleted_by;
                    is_null[35] = (deleted_by == -1);
                    bind[35].is_null= &is_null[35];
                    bind[35].length= &length[35];

                    bind[45].buffer_type= MYSQL_TYPE_LONG;
                    bind[45].buffer= (char *)&updated_at;
                    bind[45].is_null= &is_null[45];
                    bind[45].length= &length[45];

                    bind[37].buffer_type= MYSQL_TYPE_LONG;
                    bind[37].buffer= (char *)&updated_by;
                    bind[37].is_null= &is_null[37];
                    bind[37].length= &length[37];
                }
                catch(...)
                {
                    return -3895;
                }
                
                try
                {
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3835;
                    }
                }
                catch(...)
                {
                    return -3835;
                }
                
                try
                {
                    if (mysql_stmt_store_result(stmt))
                    {
                      fprintf(stderr, " mysql_stmt_store_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3836;
                    }
                }
                catch(...)
                {
                    return -3836;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -3837;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -3838;
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
            return -3839;
        }
        
    }
    else
    {
        return -3827;
    }
    if(id == 0)
    {
        return -1;
    }
    return 0;
}

int account_state::Select_account_state_by_plate(std::string curr_plate, int match_plate)
{
    char plate_[12];
    std::string statment = "SELECT *,UNIX_TIMESTAMP(intime),UNIX_TIMESTAMP(outtime),UNIX_TIMESTAMP(pay_time),UNIX_TIMESTAMP(inner_intime),UNIX_TIMESTAMP(inner_outtime),UNIX_TIMESTAMP(created_at),UNIX_TIMESTAMP(deleted_at),UNIX_TIMESTAMP(updated_at) FROM account_state WHERE SUBSTR(plate,1," + std::to_string(match_plate) +")=?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3854;
            }
        }
        catch(...)
        {
            return -3854;
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
                        return -3856;
                    }
                    strncpy( plate_, curr_plate.c_str(), match_plate);
                }
                catch(...)
                {
                    return -3856;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 1) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3857;
                    }
                }
                catch(...)
                {
                    return -3857;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3858;
                    }
                }
                catch(...)
                {
                    return -3858;
                }
                
                try
                {
                    int column_count= mysql_num_fields(prepare_meta_result);
                    if (column_count != 46) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -3859;
                    }
                }
                catch(...)
                {
                    return -3859;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3860;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3860;
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
                    bind[5].buffer_type= MYSQL_TYPE_LONG;
                    bind[5].buffer= (char *)&parking_type;
                    bind[5].is_null= &is_null[5];
                    bind[5].length= &length[5];

                    /* SHORT COLUMN */
                    bind[6].buffer_type= MYSQL_TYPE_LONG;
                    bind[6].buffer= (char *)&present_type;
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    /* SHORT COLUMN */
                    bind[38].buffer_type= MYSQL_TYPE_LONG;
                    bind[38].buffer= (char *)&intime;
                    is_null[38] = (intime == -1);
                    bind[38].is_null= &is_null[38];
                    bind[38].length= &length[38];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inserial;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[39].buffer_type= MYSQL_TYPE_LONG;
                    bind[39].buffer= (char *)&outtime;
                    is_null[39] = (outtime == -1);
                    bind[39].is_null= &is_null[39];
                    bind[39].length= &length[39];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&outserial;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* STRING COLUMN */
                    bind[40].buffer_type= MYSQL_TYPE_LONG;
                    bind[40].buffer= (char *)&pay_time;
                    is_null[40] = (pay_time == -1);
                    bind[40].is_null= &is_null[40];
                    bind[40].length= &length[40];

                    /* SHORT COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&pay_serial;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* STRING COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_LONG;
                    bind[13].buffer= (char *)&paid_sum;
                    bind[13].is_null= &is_null[13];
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_LONG;
                    bind[14].buffer= (char *)&charge_type;
                    bind[14].is_null= &is_null[14];
                    bind[14].length= &length[14];

                    /* INTEGER COLUMN */
                    bind[41].buffer_type= MYSQL_TYPE_LONG;
                    bind[41].buffer= (char *)&inner_intime;
                    is_null[41] = (inner_intime == -1);
                    bind[41].is_null= &is_null[41];
                    bind[41].length= &length[41];

                    /* SHORT COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_LONG;
                    bind[16].buffer= (char *)&inner_inserial;
                    bind[16].is_null= &is_null[16];
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[42].buffer_type= MYSQL_TYPE_LONG;
                    bind[42].buffer= (char *)&inner_outtime;
                    is_null[42] = (inner_outtime == -1);
                    bind[42].is_null= &is_null[42];
                    bind[42].length= &length[42];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_LONG;
                    bind[18].buffer= (char *)&inner_outserial;
                    bind[18].is_null= &is_null[18];
                    bind[18].length= &length[18];

                    /* TIMESTAMP COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&limit_sum;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_STRING;
                    bind[20].buffer= (char *)online_order;
                    bind[20].buffer_length= 255;
                    bind[20].is_null= &is_null[20];
                    length[20] = strlen(online_order);
                    bind[20].length= &length[20];

                    /* SHORT COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_LONG;
                    bind[21].buffer= (char *)&insite;
                    bind[21].is_null= &is_null[21];
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&charge_site;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&inner_insite;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&inner_outsite;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&prepaid_balance;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[26].buffer_type= MYSQL_TYPE_LONG;
                    bind[26].buffer= (char *)&l2_id;
                    bind[26].is_null= &is_null[26];
                    bind[26].length= &length[26];

                    /* SHORT COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_LONG;
                    bind[27].buffer= (char *)&prepaid_account_id;
                    bind[27].is_null= &is_null[27];
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)hour_ticket_num;
                    bind[28].buffer_length= 20;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(hour_ticket_num);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_LONG;
                    bind[29].buffer= (char *)&hour_ticket_type;
                    bind[29].is_null= &is_null[29];
                    bind[29].length= &length[29];

                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&total_sum;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    bind[31].buffer_type= MYSQL_TYPE_LONG;
                    bind[31].buffer= (char *)&is_deleted;
                    bind[31].is_null= &is_null[31];
                    bind[31].length= &length[31];

                    bind[43].buffer_type= MYSQL_TYPE_LONG;
                    bind[43].buffer= (char *)&created_at;
                    bind[43].is_null= &is_null[43];
                    bind[43].length= &length[43];

                    bind[33].buffer_type= MYSQL_TYPE_LONG;
                    bind[33].buffer= (char *)&created_by;
                    bind[33].is_null= &is_null[33];
                    bind[33].length= &length[33];

                    bind[44].buffer_type= MYSQL_TYPE_LONG;
                    bind[44].buffer= (char *)&deleted_at;
                    is_null[44] = (deleted_at == -1);
                    bind[44].is_null= &is_null[44];
                    bind[44].length= &length[44];

                    bind[35].buffer_type= MYSQL_TYPE_LONG;
                    bind[35].buffer= (char *)&deleted_by;
                    is_null[35] = (deleted_by == -1);
                    bind[35].is_null= &is_null[35];
                    bind[35].length= &length[35];

                    bind[45].buffer_type= MYSQL_TYPE_LONG;
                    bind[45].buffer= (char *)&updated_at;
                    bind[45].is_null= &is_null[45];
                    bind[45].length= &length[45];

                    bind[37].buffer_type= MYSQL_TYPE_LONG;
                    bind[37].buffer= (char *)&updated_by;
                    bind[37].is_null= &is_null[37];
                    bind[37].length= &length[37];
                }
                catch(...)
                {
                    return -3895;
                }
                
                try
                {
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3861;
                    }
                }
                catch(...)
                {
                    return -3861;
                }
                
                try
                {
                    if (mysql_stmt_store_result(stmt))
                    {
                      fprintf(stderr, " mysql_stmt_store_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3862;
                    }
                }
                catch(...)
                {
                    return -3862;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -3863;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -3864;
                }
                
            }
            else
            {
                return -3855;
            }
        }
        catch(...)
        {
            return -3855;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3865;
        }
        
    }
    else
    {
        return -3853;
    }
    if(id == 0)
    {
        return -1;
    }
    return 0;
}

int account_state::Select_account_state_by_ID_park_lot_id(int index, int park_lot_id)
{
    int id_;
    int park_lot_id_;
    std::string statment = "SELECT *,UNIX_TIMESTAMP(intime),UNIX_TIMESTAMP(outtime),UNIX_TIMESTAMP(pay_time),UNIX_TIMESTAMP(inner_intime),UNIX_TIMESTAMP(inner_outtime),UNIX_TIMESTAMP(created_at),UNIX_TIMESTAMP(deleted_at),UNIX_TIMESTAMP(updated_at) FROM account_state WHERE id=? and parking_lot_id = ?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3815;
            }
        }
        catch(...)
        {
            return -3815;
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
                        return -3817;
                    }
                    id_ = index;
                    park_lot_id_ = park_lot_id;
                }
                catch(...)
                {
                    return -3817;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 2) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3818;
                    }
                }
                catch(...)
                {
                    return -3818;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3819;
                    }
                }
                catch(...)
                {
                     return -3819;
                }
                
                try
                {
                    int column_count= mysql_num_fields(prepare_meta_result);
                    if (column_count != 46) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -3820;
                    }
                }
                catch(...)
                {
                    return -3820;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3821;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3821;
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
                    bind[5].buffer_type= MYSQL_TYPE_LONG;
                    bind[5].buffer= (char *)&parking_type;
                    bind[5].is_null= &is_null[5];
                    bind[5].length= &length[5];

                    /* SHORT COLUMN */
                    bind[6].buffer_type= MYSQL_TYPE_LONG;
                    bind[6].buffer= (char *)&present_type;
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    /* SHORT COLUMN */
                    bind[38].buffer_type= MYSQL_TYPE_LONG;
                    bind[38].buffer= (char *)&intime;
                    is_null[38] = (intime == -1);
                    bind[38].is_null= &is_null[38];
                    bind[38].length= &length[38];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inserial;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[39].buffer_type= MYSQL_TYPE_LONG;
                    bind[39].buffer= (char *)&outtime;
                    is_null[39] = (outtime == -1);
                    bind[39].is_null= &is_null[39];
                    bind[39].length= &length[39];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&outserial;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* STRING COLUMN */
                    bind[40].buffer_type= MYSQL_TYPE_LONG;
                    bind[40].buffer= (char *)&pay_time;
                    is_null[40] = (pay_time == -1);
                    bind[40].is_null= &is_null[40];
                    bind[40].length= &length[40];

                    /* SHORT COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&pay_serial;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* STRING COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_LONG;
                    bind[13].buffer= (char *)&paid_sum;
                    bind[13].is_null= &is_null[13];
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_LONG;
                    bind[14].buffer= (char *)&charge_type;
                    bind[14].is_null= &is_null[14];
                    bind[14].length= &length[14];

                    /* INTEGER COLUMN */
                    bind[41].buffer_type= MYSQL_TYPE_LONG;
                    bind[41].buffer= (char *)&inner_intime;
                    is_null[41] = (inner_intime == -1);
                    bind[41].is_null= &is_null[41];
                    bind[41].length= &length[41];

                    /* SHORT COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_LONG;
                    bind[16].buffer= (char *)&inner_inserial;
                    bind[16].is_null= &is_null[16];
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[42].buffer_type= MYSQL_TYPE_LONG;
                    bind[42].buffer= (char *)&inner_outtime;
                    is_null[42] = (inner_outtime == -1);
                    bind[42].is_null= &is_null[42];
                    bind[42].length= &length[42];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_LONG;
                    bind[18].buffer= (char *)&inner_outserial;
                    bind[18].is_null= &is_null[18];
                    bind[18].length= &length[18];

                    /* TIMESTAMP COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&limit_sum;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_STRING;
                    bind[20].buffer= (char *)online_order;
                    bind[20].buffer_length= 255;
                    bind[20].is_null= &is_null[20];
                    length[20] = strlen(online_order);
                    bind[20].length= &length[20];

                    /* SHORT COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_LONG;
                    bind[21].buffer= (char *)&insite;
                    bind[21].is_null= &is_null[21];
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&charge_site;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&inner_insite;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&inner_outsite;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&prepaid_balance;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[26].buffer_type= MYSQL_TYPE_LONG;
                    bind[26].buffer= (char *)&l2_id;
                    bind[26].is_null= &is_null[26];
                    bind[26].length= &length[26];

                    /* SHORT COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_LONG;
                    bind[27].buffer= (char *)&prepaid_account_id;
                    bind[27].is_null= &is_null[27];
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)hour_ticket_num;
                    bind[28].buffer_length= 20;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(hour_ticket_num);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_LONG;
                    bind[29].buffer= (char *)&hour_ticket_type;
                    bind[29].is_null= &is_null[29];
                    bind[29].length= &length[29];

                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&total_sum;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    bind[31].buffer_type= MYSQL_TYPE_LONG;
                    bind[31].buffer= (char *)&is_deleted;
                    bind[31].is_null= &is_null[31];
                    bind[31].length= &length[31];

                    bind[43].buffer_type= MYSQL_TYPE_LONG;
                    bind[43].buffer= (char *)&created_at;
                    bind[43].is_null= &is_null[43];
                    bind[43].length= &length[43];

                    bind[33].buffer_type= MYSQL_TYPE_LONG;
                    bind[33].buffer= (char *)&created_by;
                    bind[33].is_null= &is_null[33];
                    bind[33].length= &length[33];

                    bind[44].buffer_type= MYSQL_TYPE_LONG;
                    bind[44].buffer= (char *)&deleted_at;
                    is_null[44] = (deleted_at == -1);
                    bind[44].is_null= &is_null[44];
                    bind[44].length= &length[44];

                    bind[35].buffer_type= MYSQL_TYPE_LONG;
                    bind[35].buffer= (char *)&deleted_by;
                    is_null[35] = (deleted_by == -1);
                    bind[35].is_null= &is_null[35];
                    bind[35].length= &length[35];

                    bind[45].buffer_type= MYSQL_TYPE_LONG;
                    bind[45].buffer= (char *)&updated_at;
                    bind[45].is_null= &is_null[45];
                    bind[45].length= &length[45];

                    bind[37].buffer_type= MYSQL_TYPE_LONG;
                    bind[37].buffer= (char *)&updated_by;
                    bind[37].is_null= &is_null[37];
                    bind[37].length= &length[37];
                }
                catch(...)
                {
                    return -3896;
                }
                
                try
                {
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3822;
                    }
                }
                catch(...)
                {
                    return -3822;
                }
                
                try
                {
                    if (mysql_stmt_store_result(stmt))
                    {
                      fprintf(stderr, " mysql_stmt_store_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3823;
                    }
                }
                catch(...)
                {
                    return -3823;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -3824;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -3825;
                }
                
            }
            else
            {
                return -3816;
            }
        }
        catch(...)
        {
            return -3816;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3826;
        }
        
    }
    else
    {
        return -3814;
    }
    if(id == 0)
    {
        return -1;
    }
    return 0;
}

int account_state::Select_account_state_by_ticket_park_lot_id(std::string _ticket, int park_lot_id)
{
    char ticket_[20];
    int park_lot_id_;
    std::string statment = "SELECT *,UNIX_TIMESTAMP(intime),UNIX_TIMESTAMP(outtime),UNIX_TIMESTAMP(pay_time),UNIX_TIMESTAMP(inner_intime),UNIX_TIMESTAMP(inner_outtime),UNIX_TIMESTAMP(created_at),UNIX_TIMESTAMP(deleted_at),UNIX_TIMESTAMP(updated_at) FROM account_state WHERE ticket=? and parking_lot_id = ?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3841;
            }
        }
        catch(...)
        {
            return -3841;
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
                        return -3843;
                    }
                    strcpy( ticket_, _ticket.c_str());
                    park_lot_id_ = park_lot_id;
                }
                catch(...)
                {
                    return -3843;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 2) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3844;
                    }
                }
                catch(...)
                {
                    return -3844;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3845;
                    }
                }
                catch(...)
                {
                    return -3845;
                }
                
                try
                {
                    int column_count= mysql_num_fields(prepare_meta_result);
                    //std::cout << column_count << std::endl;
                    if (column_count != 46) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -3846;
                    }
                }
                catch(...)
                {
                    return -3846;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3847;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3847;
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
                    bind[5].buffer_type= MYSQL_TYPE_LONG;
                    bind[5].buffer= (char *)&parking_type;
                    bind[5].is_null= &is_null[5];
                    bind[5].length= &length[5];

                    /* SHORT COLUMN */
                    bind[6].buffer_type= MYSQL_TYPE_LONG;
                    bind[6].buffer= (char *)&present_type;
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    /* SHORT COLUMN */
                    bind[38].buffer_type= MYSQL_TYPE_LONG;
                    bind[38].buffer= (char *)&intime;
                    is_null[38] = (intime == -1);
                    bind[38].is_null= &is_null[38];
                    bind[38].length= &length[38];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inserial;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[39].buffer_type= MYSQL_TYPE_LONG;
                    bind[39].buffer= (char *)&outtime;
                    is_null[39] = (outtime == -1);
                    bind[39].is_null= &is_null[39];
                    bind[39].length= &length[39];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&outserial;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* STRING COLUMN */
                    bind[40].buffer_type= MYSQL_TYPE_LONG;
                    bind[40].buffer= (char *)&pay_time;
                    is_null[40] = (pay_time == -1);
                    bind[40].is_null= &is_null[40];
                    bind[40].length= &length[40];

                    /* SHORT COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&pay_serial;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* STRING COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_LONG;
                    bind[13].buffer= (char *)&paid_sum;
                    bind[13].is_null= &is_null[13];
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_LONG;
                    bind[14].buffer= (char *)&charge_type;
                    bind[14].is_null= &is_null[14];
                    bind[14].length= &length[14];

                    /* INTEGER COLUMN */
                    bind[41].buffer_type= MYSQL_TYPE_LONG;
                    bind[41].buffer= (char *)&inner_intime;
                    is_null[41] = (inner_intime == -1);
                    bind[41].is_null= &is_null[41];
                    bind[41].length= &length[41];

                    /* SHORT COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_LONG;
                    bind[16].buffer= (char *)&inner_inserial;
                    bind[16].is_null= &is_null[16];
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[42].buffer_type= MYSQL_TYPE_LONG;
                    bind[42].buffer= (char *)&inner_outtime;
                    is_null[42] = (inner_outtime == -1);
                    bind[42].is_null= &is_null[42];
                    bind[42].length= &length[42];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_LONG;
                    bind[18].buffer= (char *)&inner_outserial;
                    bind[18].is_null= &is_null[18];
                    bind[18].length= &length[18];

                    /* TIMESTAMP COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&limit_sum;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_STRING;
                    bind[20].buffer= (char *)online_order;
                    bind[20].buffer_length= 255;
                    bind[20].is_null= &is_null[20];
                    length[20] = strlen(online_order);
                    bind[20].length= &length[20];

                    /* SHORT COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_LONG;
                    bind[21].buffer= (char *)&insite;
                    bind[21].is_null= &is_null[21];
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&charge_site;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&inner_insite;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&inner_outsite;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&prepaid_balance;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[26].buffer_type= MYSQL_TYPE_LONG;
                    bind[26].buffer= (char *)&l2_id;
                    bind[26].is_null= &is_null[26];
                    bind[26].length= &length[26];

                    /* SHORT COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_LONG;
                    bind[27].buffer= (char *)&prepaid_account_id;
                    bind[27].is_null= &is_null[27];
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)hour_ticket_num;
                    bind[28].buffer_length= 20;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(hour_ticket_num);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_LONG;
                    bind[29].buffer= (char *)&hour_ticket_type;
                    bind[29].is_null= &is_null[29];
                    bind[29].length= &length[29];

                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&total_sum;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    bind[31].buffer_type= MYSQL_TYPE_LONG;
                    bind[31].buffer= (char *)&is_deleted;
                    bind[31].is_null= &is_null[31];
                    bind[31].length= &length[31];

                    bind[43].buffer_type= MYSQL_TYPE_LONG;
                    bind[43].buffer= (char *)&created_at;
                    bind[43].is_null= &is_null[43];
                    bind[43].length= &length[43];

                    bind[33].buffer_type= MYSQL_TYPE_LONG;
                    bind[33].buffer= (char *)&created_by;
                    bind[33].is_null= &is_null[33];
                    bind[33].length= &length[33];

                    bind[44].buffer_type= MYSQL_TYPE_LONG;
                    bind[44].buffer= (char *)&deleted_at;
                    is_null[44] = (deleted_at == -1);
                    bind[44].is_null= &is_null[44];
                    bind[44].length= &length[44];

                    bind[35].buffer_type= MYSQL_TYPE_LONG;
                    bind[35].buffer= (char *)&deleted_by;
                    is_null[35] = (deleted_by == -1);
                    bind[35].is_null= &is_null[35];
                    bind[35].length= &length[35];

                    bind[45].buffer_type= MYSQL_TYPE_LONG;
                    bind[45].buffer= (char *)&updated_at;
                    bind[45].is_null= &is_null[45];
                    bind[45].length= &length[45];

                    bind[37].buffer_type= MYSQL_TYPE_LONG;
                    bind[37].buffer= (char *)&updated_by;
                    bind[37].is_null= &is_null[37];
                    bind[37].length= &length[37];
                }
                catch(...)
                {
                    return -3895;
                }
                
                try
                {
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3848;
                    }
                }
                catch(...)
                {
                    return -3848;
                }
                
                try
                {
                    if (mysql_stmt_store_result(stmt))
                    {
                      fprintf(stderr, " mysql_stmt_store_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3849;
                    }
                }
                catch(...)
                {
                    return -3849;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -3850;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -3851;
                }
                
            }
            else
            {
                return -3842;
            }
        }
        catch(...)
        {
            return -3842;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3852;
        }
        
    }
    else
    {
        return -3840;
    }
    if(id == 0)
    {
        return -1;
    }
    return 0;
}

int account_state::Select_account_state_by_plate_park_lot_id(std::string curr_plate, int match_plate, int park_lot_id)
{
    char plate_[12];
    int park_lot_id_;
    std::string statment = "SELECT *,UNIX_TIMESTAMP(intime),UNIX_TIMESTAMP(outtime),UNIX_TIMESTAMP(pay_time),UNIX_TIMESTAMP(inner_intime),UNIX_TIMESTAMP(inner_outtime),UNIX_TIMESTAMP(created_at),UNIX_TIMESTAMP(deleted_at),UNIX_TIMESTAMP(updated_at) FROM account_state WHERE SUBSTR(plate,1," + std::to_string(match_plate) +")=? and parking_lot_id = ?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3867;
            }
        }
        catch(...)
        {
            return -3867;
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
                        return -3869;
                    }
                    strncpy( plate_, curr_plate.c_str(), match_plate);
                    park_lot_id_ = park_lot_id;
                }
                catch(...)
                {
                    return -3869;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 2) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3870;
                    }
                }
                catch(...)
                {
                    return -3870;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -3871;
                    }
                }
                catch(...)
                {
                    return -3871;
                }
                
                try
                {
                    int column_count= mysql_num_fields(prepare_meta_result);
                    if (column_count != 46) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -3872;
                    }
                }
                catch(...)
                {
                    return -3872;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3873;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3873;
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
                    bind[5].buffer_type= MYSQL_TYPE_LONG;
                    bind[5].buffer= (char *)&parking_type;
                    bind[5].is_null= &is_null[5];
                    bind[5].length= &length[5];

                    /* SHORT COLUMN */
                    bind[6].buffer_type= MYSQL_TYPE_LONG;
                    bind[6].buffer= (char *)&present_type;
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    /* SHORT COLUMN */
                    bind[38].buffer_type= MYSQL_TYPE_LONG;
                    bind[38].buffer= (char *)&intime;
                    is_null[38] = (intime == -1);
                    bind[38].is_null= &is_null[38];
                    bind[38].length= &length[38];

                    /* SHORT COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&inserial;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* SHORT COLUMN */
                    bind[39].buffer_type= MYSQL_TYPE_LONG;
                    bind[39].buffer= (char *)&outtime;
                    is_null[39] = (outtime == -1);
                    bind[39].is_null= &is_null[39];
                    bind[39].length= &length[39];

                    /* SHORT COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&outserial;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* STRING COLUMN */
                    bind[40].buffer_type= MYSQL_TYPE_LONG;
                    bind[40].buffer= (char *)&pay_time;
                    is_null[40] = (pay_time == -1);
                    bind[40].is_null= &is_null[40];
                    bind[40].length= &length[40];

                    /* SHORT COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&pay_serial;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    /* STRING COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_LONG;
                    bind[13].buffer= (char *)&paid_sum;
                    bind[13].is_null= &is_null[13];
                    bind[13].length= &length[13];

                    /* STRING COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_LONG;
                    bind[14].buffer= (char *)&charge_type;
                    bind[14].is_null= &is_null[14];
                    bind[14].length= &length[14];

                    /* INTEGER COLUMN */
                    bind[41].buffer_type= MYSQL_TYPE_LONG;
                    bind[41].buffer= (char *)&inner_intime;
                    is_null[41] = (inner_intime == -1);
                    bind[41].is_null= &is_null[41];
                    bind[41].length= &length[41];

                    /* SHORT COLUMN */
                    bind[16].buffer_type= MYSQL_TYPE_LONG;
                    bind[16].buffer= (char *)&inner_inserial;
                    bind[16].is_null= &is_null[16];
                    bind[16].length= &length[16];

                    /* SHORT COLUMN */
                    bind[42].buffer_type= MYSQL_TYPE_LONG;
                    bind[42].buffer= (char *)&inner_outtime;
                    is_null[42] = (inner_outtime == -1);
                    bind[42].is_null= &is_null[42];
                    bind[42].length= &length[42];

                    /* SHORT COLUMN */
                    bind[18].buffer_type= MYSQL_TYPE_LONG;
                    bind[18].buffer= (char *)&inner_outserial;
                    bind[18].is_null= &is_null[18];
                    bind[18].length= &length[18];

                    /* TIMESTAMP COLUMN */
                    bind[19].buffer_type= MYSQL_TYPE_LONG;
                    bind[19].buffer= (char *)&limit_sum;
                    bind[19].is_null= &is_null[19];
                    bind[19].length= &length[19];

                    /* TIMESTAMP COLUMN */
                    bind[20].buffer_type= MYSQL_TYPE_STRING;
                    bind[20].buffer= (char *)online_order;
                    bind[20].buffer_length= 255;
                    bind[20].is_null= &is_null[20];
                    length[20] = strlen(online_order);
                    bind[20].length= &length[20];

                    /* SHORT COLUMN */
                    bind[21].buffer_type= MYSQL_TYPE_LONG;
                    bind[21].buffer= (char *)&insite;
                    bind[21].is_null= &is_null[21];
                    bind[21].length= &length[21];

                    /* SHORT COLUMN */
                    bind[22].buffer_type= MYSQL_TYPE_LONG;
                    bind[22].buffer= (char *)&charge_site;
                    bind[22].is_null= &is_null[22];
                    bind[22].length= &length[22];

                    /* SHORT COLUMN */
                    bind[23].buffer_type= MYSQL_TYPE_LONG;
                    bind[23].buffer= (char *)&inner_insite;
                    bind[23].is_null= &is_null[23];
                    bind[23].length= &length[23];

                    /* SHORT COLUMN */
                    bind[24].buffer_type= MYSQL_TYPE_LONG;
                    bind[24].buffer= (char *)&inner_outsite;
                    bind[24].is_null= &is_null[24];
                    bind[24].length= &length[24];

                    /* SHORT COLUMN */
                    bind[25].buffer_type= MYSQL_TYPE_LONG;
                    bind[25].buffer= (char *)&prepaid_balance;
                    bind[25].is_null= &is_null[25];
                    bind[25].length= &length[25];

                    /* SHORT COLUMN */
                    bind[26].buffer_type= MYSQL_TYPE_LONG;
                    bind[26].buffer= (char *)&l2_id;
                    bind[26].is_null= &is_null[26];
                    bind[26].length= &length[26];

                    /* SHORT COLUMN */
                    bind[27].buffer_type= MYSQL_TYPE_LONG;
                    bind[27].buffer= (char *)&prepaid_account_id;
                    bind[27].is_null= &is_null[27];
                    bind[27].length= &length[27];

                    /* VARCHAR COLUMN */
                    bind[28].buffer_type= MYSQL_TYPE_STRING;
                    bind[28].buffer= (char *)hour_ticket_num;
                    bind[28].buffer_length= 20;
                    bind[28].is_null= &is_null[28];
                    length[28] = strlen(hour_ticket_num);
                    bind[28].length= &length[28];

                    /* VARCHAR COLUMN */
                    bind[29].buffer_type= MYSQL_TYPE_LONG;
                    bind[29].buffer= (char *)&hour_ticket_type;
                    bind[29].is_null= &is_null[29];
                    bind[29].length= &length[29];

                    bind[30].buffer_type= MYSQL_TYPE_LONG;
                    bind[30].buffer= (char *)&total_sum;
                    bind[30].is_null= &is_null[30];
                    bind[30].length= &length[30];

                    bind[31].buffer_type= MYSQL_TYPE_LONG;
                    bind[31].buffer= (char *)&is_deleted;
                    bind[31].is_null= &is_null[31];
                    bind[31].length= &length[31];

                    bind[43].buffer_type= MYSQL_TYPE_LONG;
                    bind[43].buffer= (char *)&created_at;
                    bind[43].is_null= &is_null[43];
                    bind[43].length= &length[43];

                    bind[33].buffer_type= MYSQL_TYPE_LONG;
                    bind[33].buffer= (char *)&created_by;
                    bind[33].is_null= &is_null[33];
                    bind[33].length= &length[33];

                    bind[44].buffer_type= MYSQL_TYPE_LONG;
                    bind[44].buffer= (char *)&deleted_at;
                    is_null[44] = (deleted_at == -1);
                    bind[44].is_null= &is_null[44];
                    bind[44].length= &length[44];

                    bind[35].buffer_type= MYSQL_TYPE_LONG;
                    bind[35].buffer= (char *)&deleted_by;
                    is_null[35] = (deleted_by == -1);
                    bind[35].is_null= &is_null[35];
                    bind[35].length= &length[35];

                    bind[45].buffer_type= MYSQL_TYPE_LONG;
                    bind[45].buffer= (char *)&updated_at;
                    bind[45].is_null= &is_null[45];
                    bind[45].length= &length[45];

                    bind[37].buffer_type= MYSQL_TYPE_LONG;
                    bind[37].buffer= (char *)&updated_by;
                    bind[37].is_null= &is_null[37];
                    bind[37].length= &length[37];
                }
                catch(...)
                {
                    return -3895;
                }
                
                try
                {
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3874;
                    }
                }
                catch(...)
                {
                    return -3874;
                }
                
                try
                {
                    if (mysql_stmt_store_result(stmt))
                    {
                      fprintf(stderr, " mysql_stmt_store_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -3875;
                    }
                }
                catch(...)
                {
                    return -3875;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -3876;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -3877;
                }
                
            }
            else
            {
                return -3868;
            }
        }
        catch(...)
        {
            return -3868;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3878;
        }
        
    }
    else
    {
        return -3866;
    }
    if(id == 0)
    {
        return -1;
    }
    return 0;
}

int account_state::Delete_account_state()
{
    try
    {
        parking_lot_id = 0;
        strcpy(ticket, "");
        ticket_type = 0;
        strcpy(plate, "");
        parking_type = 64;
        present_type = 0;
        intime = -1;
        inserial = 0;
        outtime = -1;
        outserial = 0;
        pay_time = -1;
        pay_serial = 0;
        paid_sum = 0;
        charge_type = 255;
        inner_intime = -1;
        inner_inserial = 0;
        inner_outtime = -1;
        inner_outserial = 0;
        limit_sum = 0;
        strcpy(online_order, "");
        insite = 255;
        charge_site = 255;
        inner_insite = 255;
        inner_outsite = 255;
        prepaid_balance = 0;
        l2_id = 255;
        prepaid_account_id = 65535;
        strcpy(hour_ticket_num, "");
        hour_ticket_type = 0;
        total_sum = 0;
        is_deleted = 0;
        created_at = -1;
        created_by = Reference_date; 
        deleted_at = -1;
        deleted_by = -1;
        updated_at = Reference_date;
        updated_by = 0;
    }
    catch(...)
    {
        return -3898;
    }
    
    
    std::string statment = "DELETE FROM `account_state` WHERE `id`= ? ";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -3888;
            }
        }
        catch(...)
        {
            return -3888;
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
                        return -3890;
                    }
                }
                catch(...)
                {
                    return -3890;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 1) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -3891;
                    }
                }
                catch(...)
                {
                    return -3891;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -3892;
                    }
                    if (mysql_stmt_affected_rows(stmt) != 1)
                    {
                        return -3892;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -3892;
                }
                
                    
            }
            else
            {
                return -3889;
            }
        }
        catch(...)
        {
            return -3889;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -3893;
        }
        
    }
    else
    {
        return -3887;
    }
    id = 0;
    return 0;
}

int account_state::print_account_state_variables()
{
    try
    {
        std::cout << "id = " << id << std::endl;
        std::cout << "parking_lot_id = " << parking_lot_id << std::endl;
        std::cout << "ticket = " << ticket << std::endl;
        std::cout << "ticket_type = " << ticket_type << std::endl;
        std::cout << "plate = " << plate << std::endl;
        std::cout << "parking_type = " << parking_type << std::endl;
        std::cout << "present_type = " << present_type << std::endl;
        std::cout << "intime = " << Print_time(intime) << std::endl;
        std::cout << "inserial = " << inserial << std::endl;
        std::cout << "outtime = " << Print_time(outtime) << std::endl;
        std::cout << "outserial = " << outserial << std::endl;
        std::cout << "pay_time = " << Print_time(pay_time) << std::endl;
        std::cout << "pay_serial = " << pay_serial << std::endl;
        std::cout << "paid_sum = " << paid_sum << std::endl;
        std::cout << "charge_type = " << charge_type  << std::endl;
        std::cout << "inner_intime = " << Print_time(inner_intime)  << std::endl;
        std::cout << "inner_inserial = " << inner_inserial << std::endl;
        std::cout << "inner_outtime = " << Print_time(inner_outtime) << std::endl;
        std::cout << "inner_outserial = " << inner_outserial << std::endl;
        std::cout << "limit_sum = " << limit_sum  << std::endl;
        std::cout << "online_order = " << online_order << std::endl;
        std::cout << "insite = " << insite << std::endl;
        std::cout << "charge_site = " << charge_site << std::endl;
        std::cout << "inner_insite = " << inner_insite  << std::endl;
        std::cout << "inner_outsite = " << inner_outsite  << std::endl;
        std::cout << "prepaid_balance = " << prepaid_balance << std::endl;
        std::cout << "l2_id = " << l2_id << std::endl;
        std::cout << "prepaid_account_id = " << prepaid_account_id << std::endl;
        std::cout << "hour_ticket_num = " << hour_ticket_num << std::endl;
        std::cout << "hour_ticket_type = " << hour_ticket_type << std::endl;
        std::cout << "total_sum = " << total_sum << std::endl;
        std::cout << "is_deleted = " << is_deleted << std::endl;
        std::cout << "created_at = " << Print_time(created_at) << std::endl;
        std::cout << "created_by = " << created_by << std::endl;
        std::cout << "deleted_at = " << Print_time(deleted_at) << std::endl;
        std::cout << "deleted_by = " << deleted_by << std::endl;
        std::cout << "updated_at = " << Print_time(updated_at) << std::endl;
        std::cout << "updated_by = " << updated_by << std::endl;
    }
    catch(...)
    {
        return -3894;
    }
    return 0;
}
