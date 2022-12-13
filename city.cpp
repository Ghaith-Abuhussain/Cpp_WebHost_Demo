#include "city.h"

city::city(MYSQL *_mysql)
{
    mysql = _mysql;
}

city::~city()
{

}

void city::Print_city()
{
    printf("%d %d %s %s %d %s %d %s %d %s %d\n",
            id,
            country_id,
            name_ar,
            name_en,
            is_deleted,
            Print_time(created_at).c_str(),
            created_by,
            Print_time(deleted_at).c_str(),
            deleted_by,
            Print_time(updated_at).c_str(),
            updated_by);
}

bool city::select_city(int index)
{
    int id_;
    std::string statment = "SELECT * , Unix_Timestamp(created_at), Unix_Timestamp(deleted_at), Unix_Timestamp(updated_at) FROM city WHERE id=? and is_deleted=0";
    if (mysql != NULL)   
    {
        stmt= mysql_stmt_init(mysql);
        if (!stmt)
        {
            fprintf(stderr, " mysql_stmt_init(), out of memory\n");
            return false;
        }
        if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
        {
            memset(bind_param, 0, sizeof(bind));

            bind_param[0].buffer_type= MYSQL_TYPE_LONG;
            bind_param[0].buffer= (char *)&id_;
            
            if (mysql_stmt_bind_param(stmt, bind_param))
            {
                fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                return false;
            }
            
            id_ = index;
            int param_count= mysql_stmt_param_count(stmt);
            

            if (param_count != 1) /* validate parameter count */
            {
                fprintf(stderr, " invalid parameter count returned by MySQL\n");
                return false;
            }

            /* Fetch result set meta information */
            prepare_meta_result = mysql_stmt_result_metadata(stmt);
            if (!prepare_meta_result)
            {
                fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                return false;
            }
            int column_count= mysql_num_fields(prepare_meta_result);
            
            if (column_count != 14) /* validate column count */
            {
                fprintf(stderr, " invalid column count returned by MySQL\n");
                return false;
            }
            
            if (mysql_stmt_execute(stmt))
            {
                fprintf(stderr, " mysql_stmt_execute(), failed\n");
                fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                return false;
            }
            memset(bind, 0, sizeof(bind));
            memset(is_null, 0, sizeof(is_null));

            bind[0].buffer_type= MYSQL_TYPE_LONG;
            bind[0].buffer= (char *)&id;
            bind[0].is_null= &is_null[0];
            bind[0].length= &length[0];
            
            bind[1].buffer_type= MYSQL_TYPE_LONG;
            bind[1].buffer= (char *)&country_id;
            bind[1].is_null= &is_null[1];
            bind[1].length= &length[1];
            
            bind[2].buffer_type= MYSQL_TYPE_STRING;
            bind[2].buffer= (char *)&name_ar;
            bind[2].buffer_length = 50;
            bind[2].is_null= &is_null[2];
            bind[2].length= &length[2];
            
            bind[3].buffer_type= MYSQL_TYPE_STRING;
            bind[3].buffer= (char *)name_en;
            bind[3].buffer_length = 3;
            bind[3].is_null= &is_null[3];
            bind[3].length= &length[3];
            
            bind[4].buffer_type= MYSQL_TYPE_LONG;
            bind[4].buffer= (char *)&is_deleted;
            bind[4].is_null= &is_null[4];
            bind[4].length= &length[4];
                        
            bind[5].buffer_type= MYSQL_TYPE_TIMESTAMP;
            bind[5].buffer= (char *)&created_t;
            bind[5].is_null= &is_null[5];
            bind[5].length= &length[5];
                      
            bind[6].buffer_type= MYSQL_TYPE_LONG;
            bind[6].buffer= (char *)&created_by;
            bind[6].is_null= &is_null[6];
            bind[6].length= &length[6];
            
            bind[7].buffer_type= MYSQL_TYPE_TIMESTAMP;
            bind[7].buffer= (char *)&deleted_t;
            is_null[7] = 1;
            bind[7].is_null= &is_null[7];
            bind[7].length= &length[7];
            
            bind[8].buffer_type= MYSQL_TYPE_LONG;
            bind[8].buffer= (char *)&deleted_by;
            is_null[8] = 1;
            bind[8].is_null= &is_null[8];
            bind[8].length= &length[8];
            
            bind[9].buffer_type= MYSQL_TYPE_TIMESTAMP;
            bind[9].buffer= (char *)&updated_t;
            bind[9].is_null= &is_null[9];
            bind[9].length= &length[9];
            
            bind[10].buffer_type= MYSQL_TYPE_LONG;
            bind[10].buffer= (char *)&updated_by;
            bind[10].is_null= &is_null[10];
            bind[10].length= &length[10];
            
            bind[11].buffer_type= MYSQL_TYPE_LONG;
            bind[11].buffer= (char *)&created_at;
            bind[11].is_null= &is_null[11];
            bind[11].length= &length[11];
            
            bind[12].buffer_type= MYSQL_TYPE_LONG;
            bind[12].buffer= (char *)&deleted_at;
            is_null[12] = 1;
            bind[12].is_null= &is_null[12];
            bind[12].length= &length[12];

            bind[13].buffer_type= MYSQL_TYPE_LONG;
            bind[13].buffer= (char *)&updated_at;
            bind[13].is_null= &is_null[13];
            bind[13].length= &length[13];

                        
            if (mysql_stmt_bind_result(stmt, bind))
            {
              fprintf(stderr, " mysql_stmt_bind_result() failed\n");
              fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
              return false;
            }
            if (mysql_stmt_store_result(stmt))
            {
              fprintf(stderr, " mysql_stmt_store_result() failed\n");
              fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
              return false;
            }
            while (!mysql_stmt_fetch(stmt));
            mysql_free_result(prepare_meta_result);
        }
        else
        {
            return false;
        }
        mysql_stmt_close(stmt);
    }
    return true;
}
    
bool city::insert_update_city()
{
                                                //1       2             3          4           5            6               7            8             9            10             11               1  2  3  4  5                6   7                8   9                0   1
    std::string statment = "INSERT INTO `city` (`id`, `country_id`, `name_ar`, `name_en`, `is_deleted`, `created_at`, `created_by`, `deleted_at`, `deleted_by`, `updated_at`, `updated_by`) VALUES (?, ?, ?, ?, ?, FROM_UNIXTIME(?), ?, FROM_UNIXTIME(?), ?, FROM_UNIXTIME(?), ?) ON DUPLICATE KEY UPDATE id=VALUES(id), country_id=VALUES(country_id), name_ar=VALUES(name_ar), name_en=VALUES(name_en), is_deleted=VALUES(is_deleted), created_at=VALUES(created_at), created_by=VALUES(created_by), deleted_at=VALUES(deleted_at), deleted_by=VALUES(deleted_by), updated_at=VALUES(updated_at), updated_by=VALUES(updated_by)";
    if (mysql != NULL) 
    {
        stmt= mysql_stmt_init(mysql);
        if (!stmt)
        {
            fprintf(stderr, " mysql_stmt_init(), out of memory\n");
            return false;
        }
        if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
        {
            memset(bind, 0, sizeof(bind));
            memset(is_null, 0, sizeof(is_null));
            memset(length, 0, sizeof(length));
            
            bind[0].buffer_type= MYSQL_TYPE_LONG;
            bind[0].buffer= (char *)&id;
            bind[0].is_null= &is_null[0];
            bind[0].length= &length[0];
            
            bind[1].buffer_type= MYSQL_TYPE_LONG;
            bind[1].buffer= (char *)&country_id;
            bind[1].is_null= &is_null[1];
            bind[1].length= &length[1];
            
            bind[2].buffer_type= MYSQL_TYPE_STRING;
            bind[2].buffer= (char *)name_ar;
            bind[2].buffer_length = 50;
            bind[2].is_null= &is_null[2];
            length[2] = strlen(name_ar);
            bind[2].length= &length[2];
            
            bind[3].buffer_type= MYSQL_TYPE_STRING;
            bind[3].buffer= (char *)name_en;
            bind[3].buffer_length = 50;
            bind[3].is_null= &is_null[3];
            length[3] = strlen(name_en);
            bind[3].length= &length[3];
            
            bind[4].buffer_type= MYSQL_TYPE_LONG;
            bind[4].buffer= (char *)&is_deleted;
            bind[4].is_null= &is_null[4];
            bind[4].length= &length[4];
                        
            bind[5].buffer_type= MYSQL_TYPE_LONG;
            bind[5].buffer= (char *)&created_at;
            bind[5].is_null= &is_null[5];
            bind[5].length= &length[5];
                      
            bind[6].buffer_type= MYSQL_TYPE_LONG;
            bind[6].buffer= (char *)&created_by;
            bind[6].is_null= &is_null[6];
            bind[6].length= &length[6];
            
            bind[7].buffer_type= MYSQL_TYPE_LONG;
            bind[7].buffer= (char *)&deleted_at;
            is_null[7] = (deleted_at == -1);
            bind[7].is_null= &is_null[7];
            bind[7].length= &length[7];
            
            bind[8].buffer_type= MYSQL_TYPE_LONG;
            bind[8].buffer= (char *)&deleted_by;
            is_null[8] = (deleted_by == -1);
            bind[8].is_null= &is_null[8];
            bind[8].length= &length[8];
            
            bind[9].buffer_type= MYSQL_TYPE_LONG;
            bind[9].buffer= (char *)&updated_at;
            bind[9].is_null= &is_null[9];
            bind[9].length= &length[9];
            
            bind[10].buffer_type= MYSQL_TYPE_LONG;
            bind[10].buffer= (char *)&updated_by;
            bind[10].is_null= &is_null[10];
            bind[10].length= &length[10];

            if (mysql_stmt_bind_param(stmt, bind))
            {
                fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                return false;
            }
            int param_count= mysql_stmt_param_count(stmt);
            if (param_count != 11) /* validate parameter count */
            {
                fprintf(stderr, " invalid parameter count returned by MySQL\n");
                return false;
            }
            if (mysql_stmt_execute(stmt))
            {
                fprintf(stderr, " mysql_stmt_execute(), failed\n");
                fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                return false;
            }
            if (mysql_stmt_affected_rows(stmt) == 1)
            {
                fprintf(stderr, "city %d inserted\n", id);
            }
            if (mysql_stmt_affected_rows(stmt) != 1)
            {
                fprintf(stderr, "city %d updated\n", id);
            }
        }
        else
        {
            return false;
        }
        mysql_stmt_close(stmt);
    }
    return true;
}
    
bool city::delete_city()
{
    country_id = 0;
    strcpy(name_ar, "");
    strcpy(name_en, "");
    is_deleted = 0;
    created_at = 0;
    created_by = 0;
    deleted_at = -1;
    deleted_by = -1;
    updated_at = 0;
    updated_by = 0;
    int id_;
    std::string statment = "DELETE FROM `city` WHERE `id`= ?";
    if (mysql != NULL)   
    {
        stmt= mysql_stmt_init(mysql);
        if (!stmt)
        {
            fprintf(stderr, " mysql_stmt_init(), out of memory\n");
            return false;
        }
        if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
        {
            memset(bind_param, 0, sizeof(bind));
            bind_param[0].buffer_type= MYSQL_TYPE_SHORT;
            bind_param[0].buffer= (char *)&id_;
            if (mysql_stmt_bind_param(stmt, bind_param))
            {
                fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                return false;
            }
            id_ = id;
            int param_count= mysql_stmt_param_count(stmt);
            if (param_count != 1) /* validate parameter count */
            {
                fprintf(stderr, " invalid parameter count returned by MySQL\n");
                return false;
            }
            /* Fetch result set meta information */
            if (mysql_stmt_execute(stmt))
            {
                fprintf(stderr, " mysql_stmt_execute(), failed\n");
                fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                return false;
            }
            if (mysql_stmt_affected_rows(stmt) != 1)
            {
                return false;
            }    
        }
        else
        {
            return false;
        }
        mysql_stmt_close(stmt);
    }
    id = 0;
    return true;
}

