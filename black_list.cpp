#include "black_list.h"

black_list::black_list(MYSQL *_mysql)
{
    mysql = _mysql;
}

black_list::~black_list()
{

}

int black_list::Print_black_list()
{
    try
    {
        printf("%d %s %d %s %s %d %s %d %s %d %s %d\n",
                id,
                ticket,
                ticket_type,
                plate,
                description,
                is_deleted,
                Print_time(created_at).c_str(),
                created_by,
                Print_time(deleted_at).c_str(),
                deleted_by,
                Print_time(updated_at).c_str(),
                updated_by);
    }
    catch(...)
    {
        return -2729;
    }
    return 0;
}

int black_list::select_black_list(int index)
{
    int id_;
    std::string statment = "SELECT * , Unix_Timestamp(created_at), Unix_Timestamp(deleted_at), Unix_Timestamp(updated_at) FROM black_list WHERE id=?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -2702;
            }
        }
        catch(...)
        {
            return -2702;
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
                        return -2704;
                    }
                    id_ = index;
                }
                catch(...)
                {
                    return -2704;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 1) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -2705;
                    }
                }
                catch(...)
                {
                    return -2705;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -2706;
                    }
                }
                catch(...)
                {
                    return -2706;
                }
                
                try
                {
                    int column_count= mysql_num_fields(prepare_meta_result);
                    if (column_count != 15) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -2707;
                    }
                }
                catch(...)
                {
                    return -2707;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -2708;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -2708;
                }
                
                try
                {
                    memset(bind, 0, sizeof(bind));
                    memset(is_null, 0, sizeof(is_null));

                    bind[0].buffer_type= MYSQL_TYPE_LONG;
                    bind[0].buffer= (char *)&id;
                    bind[0].is_null= &is_null[0];
                    bind[0].length= &length[0];

                    bind[1].buffer_type= MYSQL_TYPE_STRING;
                    bind[1].buffer= (char *)&ticket;
                    bind[1].buffer_length = 20;
                    is_null[1] = 1;
                    bind[1].is_null= &is_null[1];
                    bind[1].length= &length[1];

                    bind[2].buffer_type= MYSQL_TYPE_LONG;
                    bind[2].buffer= (char *)&ticket_type;
                    is_null[2] = 1;
                    bind[2].is_null= &is_null[2];
                    bind[2].length= &length[2];

                    bind[3].buffer_type= MYSQL_TYPE_STRING;
                    bind[3].buffer= (char *)&plate;
                    bind[3].buffer_length = 12;
                    is_null[3] = 1;
                    bind[3].is_null= &is_null[3];
                    bind[3].length= &length[3];

                    bind[4].buffer_type= MYSQL_TYPE_STRING;
                    bind[4].buffer= (char *)&description;
                    bind[4].buffer_length = 200;
                    is_null[4] = 1;
                    bind[4].is_null= &is_null[4];
                    bind[4].length= &length[4];

                    bind[5].buffer_type= MYSQL_TYPE_LONG;
                    bind[5].buffer= (char *)&is_deleted;
                    bind[5].is_null= &is_null[5];
                    bind[5].length= &length[5];

                    bind[6].buffer_type= MYSQL_TYPE_TIMESTAMP;
                    bind[6].buffer= (char *)&created_t;
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    bind[7].buffer_type= MYSQL_TYPE_LONG;
                    bind[7].buffer= (char *)&created_by;
                    bind[7].is_null= &is_null[7];
                    bind[7].length= &length[7];

                    bind[8].buffer_type= MYSQL_TYPE_TIMESTAMP;
                    bind[8].buffer= (char *)&deleted_t;
                    is_null[8] = 1;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    bind[9].buffer_type= MYSQL_TYPE_LONG;
                    bind[9].buffer= (char *)&deleted_by;
                    is_null[9] = 1;
                    bind[9].is_null= &is_null[9];
                    bind[9].length= &length[9];

                    bind[10].buffer_type= MYSQL_TYPE_TIMESTAMP;
                    bind[10].buffer= (char *)&updated_t;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    bind[11].buffer_type= MYSQL_TYPE_LONG;
                    bind[11].buffer= (char *)&updated_by;
                    bind[11].is_null= &is_null[11];
                    bind[11].length= &length[11];

                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&created_at;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];

                    bind[13].buffer_type= MYSQL_TYPE_LONG;
                    bind[13].buffer= (char *)&deleted_at;
                    is_null[13] = 1;
                    bind[13].is_null= &is_null[13];
                    bind[13].length= &length[13];

                    bind[14].buffer_type= MYSQL_TYPE_LONG;
                    bind[14].buffer= (char *)&updated_at;
                    bind[14].is_null= &is_null[14];
                    bind[14].length= &length[14];
                }
                catch(...)
                {
                    return -2730;
                }
                
                try
                {
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -2709;
                    }
                }
                catch(...)
                {
                    return -2709;
                }
                
                try
                {
                    if (mysql_stmt_store_result(stmt))
                    {
                      fprintf(stderr, " mysql_stmt_store_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -2710;
                    }
                }
                catch(...)
                {
                    return -2710;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -2711;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -2712;
                }
                
            }
            else
            {
                return -2703;
            }
        }
        catch(...)
        {
            return -2703;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -2713;
        }
        
    }
    else
    {
        return -2701;
    }
    if(id == 0)
    {
        return -1;
    }
    return 0;
}
    
int black_list::insert_update_black_list()
{
                                                     //1       2             3          4           5              6              7           8              9             10          11           12                 1  2  3  4  5  6                7   8                9   0                1   2
    std::string statment = "INSERT INTO `black_list` (`id`, `ticket`, `ticket_type`, `plate`, `description`, `is_deleted`, `created_at`, `created_by`, `deleted_at`, `deleted_by`, `updated_at`, `updated_by`) VALUES (?, ?, ?, ?, ?, ?, FROM_UNIXTIME(?), ?, FROM_UNIXTIME(?), ?, FROM_UNIXTIME(?), ?) ON DUPLICATE KEY UPDATE id=VALUES(id), ticket=VALUES(ticket), ticket_type=VALUES(ticket_type), plate=VALUES(plate), description=VALUES(description), is_deleted=VALUES(is_deleted), created_at=VALUES(created_at), created_by=VALUES(created_by), deleted_at=VALUES(deleted_at), deleted_by=VALUES(deleted_by), updated_at=VALUES(updated_at), updated_by=VALUES(updated_by)";
    if (mysql != NULL) 
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -2715;
            }
        }
        catch(...)
        {
            return -2715;
        }
        
        try
        {
            if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
            {
                try
                {
                    memset(bind, 0, sizeof(bind));
                    memset(is_null, 0, sizeof(is_null));
                    memset(length, 0, sizeof(length));

                    bind[0].buffer_type= MYSQL_TYPE_LONG;
                    bind[0].buffer= (char *)&id;
                    bind[0].is_null= &is_null[0];
                    bind[0].length= &length[0];

                    bind[1].buffer_type= MYSQL_TYPE_STRING;
                    bind[1].buffer= (char *)ticket;
                    bind[1].buffer_length = 20;
                    bind[1].is_null= &is_null[1];
                    length[1] = strlen(ticket);
                    bind[1].length= &length[1];

                    bind[2].buffer_type= MYSQL_TYPE_LONG;
                    bind[2].buffer= (char *)&ticket_type;
                    is_null[2] = (ticket_type == -1);
                    bind[2].is_null= &is_null[2];
                    bind[2].length= &length[2];

                    bind[3].buffer_type= MYSQL_TYPE_STRING;
                    bind[3].buffer= (char *)plate;
                    bind[3].buffer_length = 12;
                    bind[3].is_null= &is_null[3];
                    length[3] = strlen(plate);
                    bind[3].length= &length[3];

                    bind[4].buffer_type= MYSQL_TYPE_STRING;
                    bind[4].buffer= (char *)description;
                    bind[4].buffer_length = 200;
                    bind[4].is_null= &is_null[4];
                    length[4] = strlen(description);
                    bind[4].length= &length[4];

                    bind[5].buffer_type= MYSQL_TYPE_LONG;
                    bind[5].buffer= (char *)&is_deleted;
                    bind[5].is_null= &is_null[5];
                    bind[5].length= &length[5];

                    bind[6].buffer_type= MYSQL_TYPE_LONG;
                    bind[6].buffer= (char *)&created_at;
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    bind[7].buffer_type= MYSQL_TYPE_LONG;
                    bind[7].buffer= (char *)&created_by;
                    bind[7].is_null= &is_null[7];
                    bind[7].length= &length[7];

                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&deleted_at;
                    is_null[8] = (deleted_at == -1);
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    bind[9].buffer_type= MYSQL_TYPE_LONG;
                    bind[9].buffer= (char *)&deleted_by;
                    is_null[9] = (deleted_by == -1);
                    bind[9].is_null= &is_null[9];
                    bind[9].length= &length[9];

                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&updated_at;
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    bind[11].buffer_type= MYSQL_TYPE_LONG;
                    bind[11].buffer= (char *)&updated_by;
                    bind[11].is_null= &is_null[11];
                    bind[11].length= &length[11];
                }
                catch(...)
                {
                    return -2731;
                }
                
                try
                {
                    if (mysql_stmt_bind_param(stmt, bind))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -2717;
                    }
                }
                catch(...)
                {
                    return -2717;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 12) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -2718;
                    }
                }
                catch(...)
                {
                    return -2718;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -2719;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -2719;
                }
                
                try
                {
                    if (mysql_stmt_affected_rows(stmt) == 1)
                    {
                        fprintf(stderr, "Car %s - %s inserted to Black List\n", ticket, plate);
                    }
                    if (mysql_stmt_affected_rows(stmt) != 1)
                    {
                        fprintf(stderr, "Car %s - %s updated into Black List\n", ticket, plate);
                    }
                }
                catch(...)
                {
                    return -2720;
                }
                
            }
            else
            {
                return -2716;
            }
        }
        catch(...)
        {
            return -2716;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -2721;
        }
        
    }
    else
    {
        return -2714;
    }
    return 0;
}
    
int black_list::delete_black_list()
{
    try
    {
        strcpy(ticket, "");
        ticket_type = -1;
        strcpy(plate, "");
        strcpy(description, "");
        is_deleted = 0;
        created_at = 0;
        created_by = 0;
        deleted_at = -1;
        deleted_by = -1;
        updated_at = 0;
        updated_by = 0;
    }
    catch(...)
    {
        return -2732;
    }
    
    int id_;
    std::string statment = "DELETE FROM `black_list` WHERE `id`= ?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -2723;
            }
        }
        catch(...)
        {
            return -2723;
        }
        
        try
        {
            if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
            {
                try
                {
                    memset(bind_param, 0, sizeof(bind));
                    bind_param[0].buffer_type= MYSQL_TYPE_SHORT;
                    bind_param[0].buffer= (char *)&id_;
                    if (mysql_stmt_bind_param(stmt, bind_param))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -2725;
                    }
                    id_ = id;
                }
                catch(...)
                {
                    return -2725;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 1) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -2726;
                    }
                }
                catch(...)
                {
                    return -2726;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -2727;
                    }
                    if (mysql_stmt_affected_rows(stmt) != 1)
                    {
                        mysql_stmt_close(stmt);
                        return -2727;
                    }    
                }
                catch(...)
                {
                    return -2727;
                }
                
            }
            else
            {
                return -2724;
            }
        }
        catch(...)
        {
            return -2724;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -2728;
        }
        
    }
    else
    {
        return -2722;
    }
    id = 0;
    return 0;
}
