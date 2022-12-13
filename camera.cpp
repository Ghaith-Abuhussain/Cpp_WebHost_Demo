#include "camera.h"

camera::camera(MYSQL *_mysql)
{
    mysql = _mysql;
}

camera::~camera()
{
    
}

int camera::Select_Camera_type_by_id(int _id)
{
    int id_;
    std::string statment = "SELECT * ,Unix_Timestamp(created_at),Unix_Timestamp(deleted_at),Unix_Timestamp(updated_at) FROM camera WHERE id = ?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -1602;
            }
        }
        catch(...)
        {
            return -1602;
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
                        return -1604;
                    }
                    id_ = _id;
                }
                catch(...)
                {
                    return -1604;
                }
                
                try
                {
                   int param_count = mysql_stmt_param_count(stmt);
                    if (param_count != 1) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -1605;
                    } 
                }
                catch(...)
                {
                    return -1605;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -1606;
                    }
                }
                catch(...)
                {
                    return -1606;
                }
                
                try
                {
                    int column_count = mysql_num_fields(prepare_meta_result);
                    if (column_count != 16) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -1607;
                    }
                }
                catch(...)
                {
                    return -1607;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -1608;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -1608;
                }
                
                try
                {
                    memset(bind, 0, sizeof(bind));
                    bind[0].buffer_type= MYSQL_TYPE_LONG;
                    bind[0].buffer= (char *)&id;
                    bind[0].is_null= &is_null[0];
                    bind[0].length= &length[0];

                    bind[1].buffer_type= MYSQL_TYPE_LONG;
                    bind[1].buffer= (char *)&parking_lot_id;
                    bind[1].is_null= &is_null[1];
                    bind[1].length= &length[1];

                    /* STRING COLUMN */
                    bind[2].buffer_type= MYSQL_TYPE_STRING;
                    bind[2].buffer= (char *)ip;
                    bind[2].buffer_length= 22;
                    bind[2].is_null= &is_null[2];
                    length[2] = strlen(ip);
                    bind[2].length= &length[2];

                    /* STRING COLUMN */
                    bind[3].buffer_type= MYSQL_TYPE_STRING;
                    bind[3].buffer= (char *)name;
                    bind[3].buffer_length= 50;
                    bind[3].is_null= &is_null[3];
                    length[3] = strlen(name);
                    bind[3].length= &length[3];
                    
                    /* STRING COLUMN */
                    bind[4].buffer_type= MYSQL_TYPE_STRING;
                    bind[4].buffer= (char *)user_name;
                    bind[4].buffer_length= 20;
                    bind[4].is_null= &is_null[4];
                    length[4] = strlen(user_name);
                    bind[4].length= &length[4];
                    
                    /* STRING COLUMN */
                    bind[5].buffer_type= MYSQL_TYPE_STRING;
                    bind[5].buffer= (char *)password;
                    bind[5].buffer_length= 20;
                    bind[5].is_null= &is_null[5];
                    length[5] = strlen(password);
                    bind[5].length= &length[5];

                    /* LONG COLUMN */
                    bind[6].buffer_type= MYSQL_TYPE_LONG;
                    bind[6].buffer= (char *)&is_deleted;
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    /* LONG COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_LONG;
                    bind[13].buffer= (char *)&created_at;
                    bind[13].is_null= &is_null[13];
                    bind[13].length= &length[13];

                    /* LONG COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&created_by;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* LONG COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_LONG;
                    bind[14].buffer= (char *)&deleted_at;
                    is_null[14] = (deleted_at == -1);
                    bind[14].is_null= &is_null[14];
                    bind[14].length= &length[14];

                    /* LONG COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&deleted_by;
                    is_null[10] = (deleted_by == -1);
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* LONG COLUMN */
                    bind[15].buffer_type= MYSQL_TYPE_LONG;
                    bind[15].buffer= (char *)&updated_at;
                    bind[15].is_null= &is_null[15];
                    bind[15].length= &length[15];

                    /* LONG COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&updated_by;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];
                }
                catch(...)
                {
                    return -1656;
                }
                
                try
                {
                    /* Bind the result buffers */
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -1609;
                    }
                }
                catch(...)
                {
                    return -1609;
                }
                
                try
                {
                    /* Now buffer all results to client */
                    if (mysql_stmt_store_result(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_store_result() failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -1610;
                    }
                }
                catch(...)
                {
                    return -1610;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -1611;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -1612;
                }
                
            }
            else
            {
                return -1603;
            }
        }
        catch(...)
        {
           return -1603; 
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -1613;
        }
        
    }
    else
    {
        return -1601;
    }
    if(id == 0)
        return  -1;
    return 0;
}

int camera::Select_Camera_type_by_address(int _address)
{
    char site_ip[22] = "";
    std::string site_address = "" + std::to_string(_address);
    std::string statment = "SELECT * ,Unix_Timestamp(created_at),Unix_Timestamp(deleted_at),Unix_Timestamp(updated_at) FROM camera WHERE ip = ?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -1615;
            }
        }
        catch(...)
        {
            return -1615;
        }
        
        try
        {
            if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
            {
                try
                {
                    memset(bind_param, 0, sizeof(bind));
                    bind_param[0].buffer_type= MYSQL_TYPE_STRING;
                    bind_param[0].buffer= (char *)site_ip;
                    bind_param[0].buffer_length= strlen(site_address.c_str());

                    if (mysql_stmt_bind_param(stmt, bind_param))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -1617;
                    }
                    strcpy( site_ip, site_address.c_str());
                }
                catch(...)
                {
                    return -1617;
                }
                
                try
                {
                    int param_count = mysql_stmt_param_count(stmt);
                    if (param_count != 1) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -1618;
                    }
                }
                catch(...)
                {
                    return -1618;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -1619;
                    }
                }
                catch(...)
                {
                    return -1619;
                }
                
                try
                {
                    int column_count = mysql_num_fields(prepare_meta_result);
                    if (column_count != 16) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -1620;
                    }
                }
                catch(...)
                {
                    return -1620;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -1621;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -1621;
                }
                
                try
                {
                    memset(bind, 0, sizeof(bind));
                    bind[0].buffer_type= MYSQL_TYPE_LONG;
                    bind[0].buffer= (char *)&id;
                    bind[0].is_null= &is_null[0];
                    bind[0].length= &length[0];

                    bind[1].buffer_type= MYSQL_TYPE_LONG;
                    bind[1].buffer= (char *)&parking_lot_id;
                    bind[1].is_null= &is_null[1];
                    bind[1].length= &length[1];

                    /* STRING COLUMN */
                    bind[2].buffer_type= MYSQL_TYPE_STRING;
                    bind[2].buffer= (char *)ip;
                    bind[2].buffer_length= 22;
                    bind[2].is_null= &is_null[2];
                    length[2] = strlen(ip);
                    bind[2].length= &length[2];

                    /* STRING COLUMN */
                    bind[3].buffer_type= MYSQL_TYPE_STRING;
                    bind[3].buffer= (char *)name;
                    bind[3].buffer_length= 50;
                    bind[3].is_null= &is_null[3];
                    length[3] = strlen(name);
                    bind[3].length= &length[3];
                    
                    /* STRING COLUMN */
                    bind[4].buffer_type= MYSQL_TYPE_STRING;
                    bind[4].buffer= (char *)user_name;
                    bind[4].buffer_length= 20;
                    bind[4].is_null= &is_null[4];
                    length[4] = strlen(user_name);
                    bind[4].length= &length[4];
                    
                    /* STRING COLUMN */
                    bind[5].buffer_type= MYSQL_TYPE_STRING;
                    bind[5].buffer= (char *)password;
                    bind[5].buffer_length= 20;
                    bind[5].is_null= &is_null[5];
                    length[5] = strlen(password);
                    bind[5].length= &length[5];

                    /* LONG COLUMN */
                    bind[6].buffer_type= MYSQL_TYPE_LONG;
                    bind[6].buffer= (char *)&is_deleted;
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    /* LONG COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_LONG;
                    bind[13].buffer= (char *)&created_at;
                    bind[13].is_null= &is_null[13];
                    bind[13].length= &length[13];

                    /* LONG COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&created_by;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* LONG COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_LONG;
                    bind[14].buffer= (char *)&deleted_at;
                    is_null[14] = (deleted_at == -1);
                    bind[14].is_null= &is_null[14];
                    bind[14].length= &length[14];

                    /* LONG COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&deleted_by;
                    is_null[10] = (deleted_by == -1);
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* LONG COLUMN */
                    bind[15].buffer_type= MYSQL_TYPE_LONG;
                    bind[15].buffer= (char *)&updated_at;
                    bind[15].is_null= &is_null[15];
                    bind[15].length= &length[15];

                    /* LONG COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&updated_by;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];
                }
                catch(...)
                {
                    return -1657;
                }
                
                try
                {
                    /* Bind the result buffers */
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                      fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                      fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                      return -1622;
                    }
                }
                catch(...)
                {
                    return -1622;
                }
                
                try
                {
                    /* Now buffer all results to client */
                    if (mysql_stmt_store_result(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_store_result() failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -1623;
                    }
                }
                catch(...)
                {
                    return -1623;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -1624;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -1625;
                }
                
            }
            else
            {
                return -1616;
            }
        }
        catch(...)
        {
            return -1616;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -1626;
        }
        
    }
    else
    {
        return -1614;
    }
    if(id == 0)
        return  -1;
    return 0;
}

int camera::Select_Camera_type_by_address_park_lot_id(int _address, int park_lot_id)
{
    char site_ip[22] = "";
    int park_lot_id_;
    std::string site_address = "" + std::to_string(_address);
    std::string statment = "SELECT * ,Unix_Timestamp(created_at),Unix_Timestamp(deleted_at),Unix_Timestamp(updated_at) FROM camera WHERE ip = ? and parking_lot_id = ?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -1628;
            }
        }
        catch(...)
        {
            return -1628;
        }
        
        try
        {
            if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
            {
                try
                {
                    memset(bind_param, 0, sizeof(bind));
                    bind_param[0].buffer_type= MYSQL_TYPE_STRING;
                    bind_param[0].buffer= (char *)site_ip;
                    bind_param[0].buffer_length= strlen(site_address.c_str());

                    bind_param[1].buffer_type= MYSQL_TYPE_LONG;
                    bind_param[1].buffer= (char *)&park_lot_id_;

                    if (mysql_stmt_bind_param(stmt, bind_param))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -1630;
                    }
                    strcpy( site_ip, site_address.c_str());
                    park_lot_id_ = park_lot_id;
                }
                catch(...)
                {
                    return -1630;
                }
                
                try
                {
                    int param_count = mysql_stmt_param_count(stmt);
                    if (param_count != 2) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -1631;
                    }
                }
                catch(...)
                {
                    return -1631;
                }
                
                try
                {
                    /* Fetch result set meta information */
                    prepare_meta_result = mysql_stmt_result_metadata(stmt);
                    if (!prepare_meta_result)
                    {
                        fprintf(stderr, " mysql_stmt_result_metadata(), returned no meta information\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -1632;
                    }
                }
                catch(...)
                {
                    return -1632;
                }
                
                try
                {
                    int column_count = mysql_num_fields(prepare_meta_result);
                    if (column_count != 16) /* validate column count */
                    {
                        fprintf(stderr, " invalid column count returned by MySQL\n");
                        return -1633;
                    }
                }
                catch(...)
                {
                    return -1633;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -1634;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -1634;
                }
                
                try
                {
                    memset(bind, 0, sizeof(bind));
                    bind[0].buffer_type= MYSQL_TYPE_LONG;
                    bind[0].buffer= (char *)&id;
                    bind[0].is_null= &is_null[0];
                    bind[0].length= &length[0];

                    bind[1].buffer_type= MYSQL_TYPE_LONG;
                    bind[1].buffer= (char *)&parking_lot_id;
                    bind[1].is_null= &is_null[1];
                    bind[1].length= &length[1];

                    /* STRING COLUMN */
                    bind[2].buffer_type= MYSQL_TYPE_STRING;
                    bind[2].buffer= (char *)ip;
                    bind[2].buffer_length= 22;
                    bind[2].is_null= &is_null[2];
                    length[2] = strlen(ip);
                    bind[2].length= &length[2];

                    /* STRING COLUMN */
                    bind[3].buffer_type= MYSQL_TYPE_STRING;
                    bind[3].buffer= (char *)name;
                    bind[3].buffer_length= 50;
                    bind[3].is_null= &is_null[3];
                    length[3] = strlen(name);
                    bind[3].length= &length[3];
                    
                    /* STRING COLUMN */
                    bind[4].buffer_type= MYSQL_TYPE_STRING;
                    bind[4].buffer= (char *)user_name;
                    bind[4].buffer_length= 20;
                    bind[4].is_null= &is_null[4];
                    length[4] = strlen(name);
                    bind[4].length= &length[4];
                    
                    /* STRING COLUMN */
                    bind[5].buffer_type= MYSQL_TYPE_STRING;
                    bind[5].buffer= (char *)password;
                    bind[5].buffer_length= 20;
                    bind[5].is_null= &is_null[5];
                    length[5] = strlen(name);
                    bind[5].length= &length[5];

                    /* LONG COLUMN */
                    bind[6].buffer_type= MYSQL_TYPE_LONG;
                    bind[6].buffer= (char *)&is_deleted;
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    /* LONG COLUMN */
                    bind[13].buffer_type= MYSQL_TYPE_LONG;
                    bind[13].buffer= (char *)&created_at;
                    bind[13].is_null= &is_null[13];
                    bind[13].length= &length[13];

                    /* LONG COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&created_by;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* LONG COLUMN */
                    bind[14].buffer_type= MYSQL_TYPE_LONG;
                    bind[14].buffer= (char *)&deleted_at;
                    is_null[14] = (deleted_at == -1);
                    bind[14].is_null= &is_null[14];
                    bind[14].length= &length[14];

                    /* LONG COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&deleted_by;
                    is_null[10] = (deleted_by == -1);
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* LONG COLUMN */
                    bind[15].buffer_type= MYSQL_TYPE_LONG;
                    bind[15].buffer= (char *)&updated_at;
                    bind[15].is_null= &is_null[15];
                    bind[15].length= &length[15];

                    /* LONG COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&updated_by;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];
                }
                catch(...)
                {
                    return -1658;
                }
                
                try
                {
                    /* Bind the result buffers */
                    if (mysql_stmt_bind_result(stmt, bind))
                    {
                        fprintf(stderr, " mysql_stmt_bind_result() failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -1635;
                    }
                }
                catch(...)
                {
                    return -1635;
                }
                
                try
                {
                    /* Now buffer all results to client */
                    if (mysql_stmt_store_result(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_store_result() failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -1636;
                    }
                }
                catch(...)
                {
                    return -1636;
                }
                
                try
                {
                    while (!mysql_stmt_fetch(stmt));
                }
                catch(...)
                {
                    return -1637;
                }
                
                try
                {
                    mysql_free_result(prepare_meta_result);
                }
                catch(...)
                {
                    return -1638;
                }
                
            }
            else
            {
                return -1629;
            } 
        }
        catch(...)
        {
            return -1629;  
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -1639;
        }
        
    }
    else
    {
        return -1627;
    }
    if(id == 0)
        return  -1;
    return 0;
}

int camera::Insert_Update_Camera_type()
{
    std::string statment = "INSERT INTO `camera` (`id`,`parking_lot_id`,`ip`,`name`, `user_name`, `password`,`is_deleted`,`created_at`,`created_by`,`deleted_at`,`deleted_by`,`updated_at`,`updated_by`) VALUES (?, ?, ?, ?, ?, ?, ?, FROM_UNIXTIME(?),?,FROM_UNIXTIME(?),?,FROM_UNIXTIME(?),?) ON DUPLICATE KEY UPDATE id=VALUES(id),parking_lot_id=VALUES(parking_lot_id),ip=VALUES(ip),name=VALUES(name),user_name=VALUES(user_name),password=VALUES(password),is_deleted=VALUES(is_deleted),created_at=VALUES(created_at),created_by=VALUES(created_by),deleted_at=VALUES(deleted_at),deleted_by=VALUES(deleted_by),updated_at=VALUES(updated_at),updated_by=VALUES(updated_by)";
    if (mysql != NULL) 
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -1641;
            }
        }
        catch(...)
        {
            return -1641;
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

                    bind[1].buffer_type= MYSQL_TYPE_LONG;
                    bind[1].buffer= (char *)&parking_lot_id;
                    bind[1].is_null= &is_null[1];
                    bind[1].length= &length[1];

                    /* STRING COLUMN */
                    bind[2].buffer_type= MYSQL_TYPE_STRING;
                    bind[2].buffer= (char *)ip;
                    bind[2].buffer_length= 22;
                    bind[2].is_null= &is_null[2];
                    length[2] = strlen(ip);
                    bind[2].length= &length[2];

                    /* STRING COLUMN */
                    bind[3].buffer_type= MYSQL_TYPE_STRING;
                    bind[3].buffer= (char *)name;
                    bind[3].buffer_length= 50;
                    bind[3].is_null= &is_null[3];
                    length[3] = strlen(name);
                    bind[3].length= &length[3];
                    
                    /* STRING COLUMN */
                    bind[4].buffer_type= MYSQL_TYPE_STRING;
                    bind[4].buffer= (char *)user_name;
                    bind[4].buffer_length= 20;
                    bind[4].is_null= &is_null[4];
                    length[4] = strlen(user_name);
                    bind[4].length= &length[4];
                    
                    /* STRING COLUMN */
                    bind[5].buffer_type= MYSQL_TYPE_STRING;
                    bind[5].buffer= (char *)password;
                    bind[5].buffer_length= 20;
                    bind[5].is_null= &is_null[5];
                    length[5] = strlen(password);
                    bind[5].length= &length[5];

                    /* LONG COLUMN */
                    bind[6].buffer_type= MYSQL_TYPE_LONG;
                    bind[6].buffer= (char *)&is_deleted;
                    bind[6].is_null= &is_null[6];
                    bind[6].length= &length[6];

                    /* LONG COLUMN */
                    bind[7].buffer_type= MYSQL_TYPE_LONG;
                    bind[7].buffer= (char *)&created_at;
                    bind[7].is_null= &is_null[7];
                    bind[7].length= &length[7];

                    /* LONG COLUMN */
                    bind[8].buffer_type= MYSQL_TYPE_LONG;
                    bind[8].buffer= (char *)&created_by;
                    bind[8].is_null= &is_null[8];
                    bind[8].length= &length[8];

                    /* LONG COLUMN */
                    bind[9].buffer_type= MYSQL_TYPE_LONG;
                    bind[9].buffer= (char *)&deleted_at;
                    is_null[9] = (deleted_at == -1);
                    bind[9].is_null= &is_null[9];
                    bind[9].length= &length[9];

                    /* LONG COLUMN */
                    bind[10].buffer_type= MYSQL_TYPE_LONG;
                    bind[10].buffer= (char *)&deleted_by;
                    is_null[10] = (deleted_by == -1);
                    bind[10].is_null= &is_null[10];
                    bind[10].length= &length[10];

                    /* LONG COLUMN */
                    bind[11].buffer_type= MYSQL_TYPE_LONG;
                    bind[11].buffer= (char *)&updated_at;
                    bind[11].is_null= &is_null[11];
                    bind[11].length= &length[11];

                    /* LONG COLUMN */
                    bind[12].buffer_type= MYSQL_TYPE_LONG;
                    bind[12].buffer= (char *)&updated_by;
                    bind[12].is_null= &is_null[12];
                    bind[12].length= &length[12];
                }
                catch(...)
                {
                    return -1659;
                }
                
                try
                {
                    if (mysql_stmt_bind_param(stmt, bind))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -1643;
                    }
                }
                catch(...)
                {
                    return -1643;
                }
                
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 13) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -1644;
                    }
                }
                catch(...)
                {
                    return -1644;
                }
                
                try
                {
                    if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -1645;
                    }
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -1645; 
                }
                
                try
                {
                    if (mysql_stmt_affected_rows(stmt) == 1)
                    {
                        fprintf(stderr, "Camera is inserted\n");
                    }
                    else
                    {
                        fprintf(stderr, "Camera is updated\n");
                    }
                }
                catch(...)
                {
                    return -1646;
                }
                
            }
            else
            {
                return -1642;
            }
        }
        catch(...)
        {
            return -1642;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -1647;
        }
        
    }
    else
    {
        return -1640;
    }
    return 0;
}

int camera::Select_sites_Connected_to_camera()
{
    site_list.clear();
    MYSQL_RES *result;
    int num_fields = 0;
    std::string query = "SELECT site_camera.site_id FROM site_camera WHERE site_camera.camera_id = " + std::to_string(id) + " and is_deleted=0";
    try
    {
        if (mysql_query(mysql, query.c_str()))
        {
            return -1661;
        }
    }
    catch(...)
    {
        return -1661;
    }
    
    try
    {
        result = mysql_store_result(mysql);
        if (result == NULL)
        {
            return -1662;
        }
        try
        {
            num_fields = mysql_num_fields(result);
        }
        catch(...)
        {
            return -1663;
        }
        
    }
    catch(...)
    {
        return -1662;
    }
    
    try
    {
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(result)))
        {
            site_list.push_back(std::stoi(row[0]));

        }
    }
    catch(...)
    {
        return -1664;
    }
    
    try
    {
        mysql_free_result(result);
    }
    catch(...)
    {
        return -1665;
    }
    
    return 0;
}

int camera::Delete_Camera_type()
{
    try
    {
        id = 0;
        parking_lot_id = 0;
        strcpy(name, "");
        strcpy(user_name, "");
        strcpy(password, "");
        is_deleted = 0;
        created_at = Reference_date;
        created_by = 0;
        deleted_at = -1;
        deleted_by = -1;
        updated_at = Reference_date;
        updated_by = 0;
    }
    catch(...)
    {
        return -1659;
    }
    std::string statment = "DELETE FROM `camera` WHERE ip= ?";
    if (mysql != NULL)   
    {
        try
        {
            stmt= mysql_stmt_init(mysql);
            if (!stmt)
            {
                fprintf(stderr, " mysql_stmt_init(), out of memory\n");
                return -1649;
            }
        }
        catch(...)
        {
            return -1649;
        }      
        try
        {
            if (!mysql_stmt_prepare(stmt,statment.c_str(),strlen(statment.c_str())))
            {
                try
                {
                     memset(bind_param, 0, sizeof(bind));
                    bind_param[0].buffer_type= MYSQL_TYPE_STRING;
                    bind_param[0].buffer= (char *)ip;
                    bind_param[0].buffer_length= strlen(ip);

                    if (mysql_stmt_bind_param(stmt, bind_param))
                    {
                        fprintf(stderr, " mysql_stmt_bind_param(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        return -1651;
                    }
                }
                catch(...)
                {
                    return -1651;
                }             
                try
                {
                    int param_count= mysql_stmt_param_count(stmt);
                    if (param_count != 1) /* validate parameter count */
                    {
                        fprintf(stderr, " invalid parameter count returned by MySQL\n");
                        return -1652;
                    }
                }
                catch(...)
                {
                    return -1652;
                }             
                try
                {
                    /* Fetch result set meta information */
                      if (mysql_stmt_execute(stmt))
                    {
                        fprintf(stderr, " mysql_stmt_execute(), failed\n");
                        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
                        mysql_stmt_close(stmt);
                        return -1653;
                    }  
                }
                catch(...)
                {
                    mysql_stmt_close(stmt);
                    return -1653;
                }
                
                try
                {
                    if (mysql_stmt_affected_rows(stmt) != 1)
                    {
                        return -1653;
                    }
                }
                catch(...)
                {
                    return -1653;
                }
                    
            }
            else
            {
                return -1650;
            }
        }
        catch(...)
        {
            return -1650;
        }
        
        try
        {
            mysql_stmt_close(stmt);
        }
        catch(...)
        {
            return -1654;
        }
        
    }
    else
    {
        return -1648;
    }
    strcpy(ip, "");
    return true;
}

int camera::print_camera_variables()
{
    
    try
    {
        std::cout << "id = " << id << std::endl;
        std::cout << "parking_lot_id = " << parking_lot_id << std::endl;
        std::cout << "ip = " << ip << std::endl;
        std::cout << "name = " << std::string(name) << std::endl;
        std::cout << "user_name = " << std::string(user_name) << std::endl;
        std::cout << "password = " << std::string(password) << std::endl;
        std::cout << "is_deleted = " << is_deleted << std::endl;
        std::cout << "created_at = " << Print_time(created_at) << std::endl;
        std::cout << "created_by = " << created_by << std::endl;
        std::cout << "deleted_at = " << Print_time(deleted_at) << std::endl;
        std::cout << "deleted_by = " << deleted_by << std::endl;
        std::cout << "updated_at = " << Print_time(updated_at) << std::endl;
        std::cout << "updated_by = " << updated_by << std::endl;
        std::cout << "site_list: ";
        for(int i=0;i<site_list.size();i++)
        {
            std::cout << site_list[i] << " ";
        }
        std::cout << std::endl;
    }
    catch(...)
    {
        return -1655;
    }
    return 0;
    
}


