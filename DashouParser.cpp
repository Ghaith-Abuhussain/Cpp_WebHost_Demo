#include "DashouParser.h"

DashouParser::DashouParser() : dashou()
{

}

DashouParser::~DashouParser()
{

}

void DashouParser::parse(char* data)
{
    header = Encoding_ASCII_GetString(data, 0, 2);
    length = 256 * data[3] + data[2];
    serial = 256 * data[5] + data[4];
    control = data[6];
    function = control & 31;
    direction = control & CONTROL_DIRECTION_UPLOAD;
    ticket = "";
    site_type = 0;
    site_address = 0;
    site_status = "";
    ticket_type = 0;
    entry_exit_type = 0;
    plate = "";
    ticketSerial = 0;
    version = "";
    switch (function)
    {
        case CONTROL_ENTRY_REQUEST_RESPONSE:
        {
            if (direction == CONTROL_DIRECTION_UPLOAD)
            {
                datetime = char_to_time_t(data[7], data[8], data[9], data[10], data[11], data[12]);
                entry_exit_type = data[13];
                ticket_type = data[14];
                ticket = Encoding_ASCII_GetString(data, 15, 19);
                plate = Encoding_ASCII_GetString(data, 34, 12);
                site_address = data[54];
                site_status = Encoding_ASCII_GetString(data, 55, 3);
                site_status_Tail = data[58];
            }
        }
        break;
        case CONTROL_EXIT_REQUEST_RESPONSE:
        {
            if (direction == CONTROL_DIRECTION_UPLOAD)
            {
                datetime = char_to_time_t(data[7], data[8], data[9], data[10], data[11], data[12]);
                Out_type = data[13];
                ticket_type = data[14];
                ticket = Encoding_ASCII_GetString(data, 15, 19);
                plate = Encoding_ASCII_GetString(data, 34, 12);
                site_address = data[90];
                site_status = Encoding_ASCII_GetString(data, 91, 3);
                site_status_Tail = data[94];
            }
        } 
        break;
        case CONTROL_TABLET_REQUEST_RESPONSE:
        {
            if (direction == CONTROL_DIRECTION_UPLOAD)
            {
                tablet_Request_type = data[7];
                switch(tablet_Request_type)
                {
                    case tablet_scans_ticket:
                    {
                        datetime = char_to_time_t(data[8], data[9], data[10], data[11], data[12], data[13]);
                        entry_exit_type = data[14];
                        ticket_type = data[15];
                        ticket = Encoding_ASCII_GetString(data, 16, 19);
                        plate = Encoding_ASCII_GetString(data, 35, 12);
                        request_address = data[47];
                        site_address = data[100];
                        site_status = Encoding_ASCII_GetString(data, 101, 3);
                        site_status_Tail = data[104];
                    }
                    break;
                    case tablet_input_license_plate_number:
                    {
                        datetime = char_to_time_t(data[8], data[9], data[10], data[11], data[12], data[13]);
                        entry_exit_type = data[14];
                        ticket_type = data[15];
                        ticket = Encoding_ASCII_GetString(data, 16, 19);
                        plate = Encoding_ASCII_GetString(data, 35, 12);
                        request_address = data[47];
                        site_address = data[100];
                        site_status = Encoding_ASCII_GetString(data, 101, 3);
                        site_status_Tail = data[104];
                    }
                    break;
                    case tablet_reads_card:
                    {
                        
                    }
                    break;
                    case tablet_reads_QR_code:
                    {
                    }
                    break;
                    case central_pay_system_tablet_payment_confirm:
                    {
                        datetime = char_to_time_t(data[8], data[9], data[10], data[11], data[12], data[13]);
                        entry_exit_type = data[14];
                        ticket_type = data[15];
                        ticket = Encoding_ASCII_GetString(data, 16, 19);
                        plate = Encoding_ASCII_GetString(data, 35, 12);
                        request_address = data[47];
                        Manual_Fee_Collection_Type = data[48];
                        chargeable_Fee = (dashou.get_TABLET_cost(data[49], data[50], data[51], data[52]));
                        cash_Received = (dashou.get_TABLET_PAID(data[53], data[54], data[55], data[56]));
                        site_address = data[100];
                        site_status = Encoding_ASCII_GetString(data, 101, 3);
                        site_status_Tail = data[104];
                    }
                    break;
                    case exit_pay_system_tablet_payment_confirm:
                    {
                        
                    }
                    break;
                    case tablet_switching_charge_type:
                    {
                        
                    }
                    break;
                    case table_confirms_prepaid_card_fee_deduction:
                    {
                        
                    }
                    break;
                    case parking_coupon_applied_on_tablet:
                    {
                        
                    }
                    break;
                    case special_let_pass:
                    {
                        
                    }
                    break;
                    case manual_open_gate:
                    {
                        
                    }
                    break;
                    case monthly_user_let_pass_as_hourly_user:
                    {
                        
                    }
                    break;
                    case close_gate:
                    {
                        
                    }
                    break;
                    case entry_preset_license_plate_number:
                    {
                        
                    }
                    break;
                    case exit_preset_license_plate_number:
                    {
                        
                    }
                    break;
                    default:
                    {

                    }
                    break;
                }
            }
        } 
        break;
        case CONTROL_INIT_REQUEST_RESPONSE:
        {
            char_to_time_t(data[7], data[8], data[9], data[10], data[11], data[12]);
            site_address = data[13];
            site_type = data[14];
            if (length > 32)
            {
                version = Encoding_ASCII_GetString(data, 15, 32);
            }
        }
        break;
        case CONTROL_HEARTBEAT:
        {
            datetime = char_to_time_t(data[7], data[8], data[9], data[10], data[11], data[12]);
            ticket = "";
            plate = "";
            site_address = data[45];
            site_status = Encoding_ASCII_GetString(data, 46, 3);
            site_type = data[49];
            site_status_Tail = data[49];
        }
        break;
        case CONTROL_PAYMENT_BOARD_STATUS:
        {
        }
        break;
        case CONTROL_ACK_FRAME:
        {
            Setting_type = data[7];
        }
        break;
        case CONTROL_Sys_PARAM_FRAME:
        {
            datetime = char_to_time_t(data[7], data[8], data[9], data[10], data[11], data[12]);
            parameterType = data[13];
            switch (parameterType)
            {
                case CONTROL_TYPE_SITE_SETTING:
                {
                    site_address			= data[15];
                    oneCard_oneCar			= data[16];
                    same_EntryExit_group		= data[17];
                    same_EntryExit_site                 = data[18] + data[19];
                    same_EntryExit_filter		= data[20];
                    entryPresetLicensePlateNumber	= data[21];
                    exitFreeLetPass			= data[22];
                    hourlyParkingFullAccessDeny         = data[23];
                    monthlyParkingFullAccessDeny	= data[24];
                    id_PresetType_id                    = data[25];
                    id_PresetSite_in_Site_Group         = data[26];
                    credentialMode			= data[27];
                    setting_siteType                    = dashou.to_String_X2(data[28]);
                    reserved                            = dashou.to_String_X2(data[29]) + dashou.to_String_X2(data[30]) + dashou.to_String_X2(data[31]);
                }
                break;
                case CONTROL_TYPE_BALANCE_NOTIFICATION:
                {
                    balanceNotificationThreshold = data[15];
                }
                break;
                case CONTROL_TYPE_EXPIRE_FORECAST:
                {
                    expireForecastThreshold = data[15];
                }
                break;
                case CONTROL_TYPE_CAMERA_SITE:
                {
                    int count = data[15];
                    for (int i = 0; i < count; i++)
                    {
                        CameraSite temp_camera_site;
                        temp_camera_site.camera_id = data[16 + 2 * i];
                        temp_camera_site.site_address = data[17 + 2 * i];
                        cameraSiteList.push_back(temp_camera_site);
                    }
                }
                break;
                case CONTROL_TYPE_NETWORK_PARAM:
                {
                }
                break;
                case CONTROL_TYPE_SITE_NAME:
                {
                    int site_count = data[15];
                    for (int i = 0; i < site_count; i++)
                    {
                        int address = data[16 + 34 * i];
                        int type = data[17 + 34 * i];
                        if (type != 0)
                        {
                            site_name = Encoding_ASCII_GetString(data, 18 + 34 * i, 32);	//site_name = Encoding_ASCII_GetString(data, 18 + 34 * i, 32);
                            break;
                        }
                    }
                }
                break;
                case CONTROL_TYPE_LED_DISPLAY:
                {
                }
                break;
                case CONTROL_TYPE_TICKET_HEADER:
                {
                }
                break;
                case CONTROL_TYPE_RECEIPT_FORMAT:
                {
                }
                break;
                case CONTROL_TYPE_CHARGE_RATE:
                {
                    site_address = data[15];
                    int rate_count = data[16];
                    for (int i = 0; i < rate_count; i++)
                    {
                        ChargingStandard temp_ChargingStandard;
                        temp_ChargingStandard.id = data[17 + 65 * i];
                        temp_ChargingStandard.name = Encoding_ASCII_GetString(data, 18 + 65 * i, 32);
                        chargingStandardList.push_back(temp_ChargingStandard);
                    }
                }
                break;
            }
        }
        break;
        default:
        {

        }
        break;
    }
};

void DashouParser::parse2(char* data)
{
    header = Encoding_ASCII_GetString(data, 0, 2);
    length = 256 * (data[3]+(1-(data[3]>=0))*256) + (data[2] + (1-(data[2]>0))*256);
    serial = 256 * (data[5]+(1-(data[5]>=0))*256) + (data[4] + (1-(data[4]>0))*256);
    control = data[10] + (1-(data[10]>=0))*256;
    function = control & 31;
    //std::cout<<control<<std::endl;
    ticket = "";
    site_type = 0;
    site_address = 0;
    ticket_type = 0;
    plate = "";
    entry_exit_type = 0;
    Setting_type = 0;
    ticketSerial = 0;
    version = "";
    gid = 256 * (data[7]+(1-(data[7]>=0))*256) + (data[6] + (1-(data[6]>0))*256);
    switch(control)
    {
        case 131:
        {
            ticket = "";
            plate = "";
            site_address = data[33] + (1-(data[33]>0))*256;
            site_status = Encoding_ASCII_GetString(data, 34, 3);
            site_status_Tail = data[37] + (1-(data[37]>0))*256;
            site_type = data[37] + (1-(data[37]>0))*256;
        }break;
        case 132:
        {
            int siz = length + 14 -1;
            function = dashou.get_X2_Number(data[19],data[20]);
            datetime = char_to_time_t(data[11], data[12], data[13], data[14], data[15], data[16]);
            switch (function)
            {
                case 128:// Initialization Request
                {
                    site_address = data[21] + (1-(data[21]>=0))*256;
                    site_type = data[22] + (1-(data[22]>=0))*256;
                    if (site_type != SITE_TYPE_TABLET_APP)
                        version = Encoding_ASCII_GetString(data, 23, 32);
                } break;
                case 21:// Zone info update
                {
                    checkSum = (data[80]+(1-(data[80]>=0))*256) + (data[81]+(1-(data[81]>=0))*256)*256;
                } break;
                case 1:    //Car Park Info
                {
                    int i = 0; int fin = 0;
                    while(i>=0 && i < 1024)
                    {
                        if((data[i] + (1-(data[i]>=0))*256) == 205)
                        {
                            fin = i;
                        }
                        i++;
                    }
                    checkSum = (data[fin-2]+(1-(data[fin-2]>=0))*256) + (data[fin-1]+(1-(data[fin-1]>=0))*256)*256;    
                }break;
                case 3:
                {
                    checkSum = (data[30]+(1-(data[30]>=0))*256) + (data[31]+(1-(data[31]>=0))*256)*256;      
                }break;
                case 7:
                {
                    int len = 0;
                    for(int i=0;i<1024; i++)
                    {
                        if((data[i]+(1-(data[i]>=0))*256) == 205 && i>10)
                        {
                            len = i;
                            break;
                        }
                    }
                    checkSum = (data[len-2]+(1-(data[len-2]>=0))*256) + (data[len-1]+(1-(data[len-1]>=0))*256)*256;    
                }
                break;
                case 50:         //In out proof model
                {
                    checkSum = (data[31]+(1-(data[31]>=0))*256) + (data[32]+(1-(data[32]>=0))*256)*256;  
                }break;
                case 10:         //confirm plate
                {
                     checkSum = (data[30]+(1-(data[30]>=0))*256) + (data[31]+(1-(data[31]>=0))*256)*256;            
                }break;
                case 11:          //auto open free
                {
                    checkSum = (data[30]+(1-(data[30]>=0))*256) + (data[31]+(1-(data[31]>=0))*256)*256;      
                }break;
                case 12:       //plate fuzzy match
                {
                    checkSum = (data[28]+(1-(data[28]>=0))*256) + (data[29]+(1-(data[29]>=0))*256)*256;      
                }break;
                case 13:        //Full no entry
                {
                    checkSum = (data[31]+(1-(data[31]>=0))*256) + (data[32]+(1-(data[32]>=0))*256)*256; 
                }break;
                case 14:         //remind balance
                {
                    checkSum = (data[31]+(1-(data[31]>=0))*256) + (data[32]+(1-(data[32]>=0))*256)*256; 
                }break;
                case 15:       //remind expiry
                {
                    checkSum = (data[31]+(1-(data[31]>=0))*256) + (data[32]+(1-(data[32]>=0))*256)*256;           
                }break;
                case 16:      //season to hourly auto
                {
                    checkSum = (data[30]+(1-(data[30]>0))*256) + (data[31]+(1-(data[31]>0))*256)*256;          
                }break;
                case 17:                        //hourly charge standard  
                {
                    checkSum = (data[30]+(1-(data[30]>=0))*256) + (data[31]+(1-(data[31]>=0))*256)*256;
                }break;
                case 18:
                {
                    int len = 0;
                    for(int i=0;i<1024; i++)
                    {
                        if((data[i]+(1-(data[i]>=0))*256) == 205 && i>10)
                        {
                            len = i;
                            break;
                        }
                    }
                    checkSum = (data[len-2]+(1-(data[len-2]>=0))*256) + (data[len-1]+(1-(data[len-1]>=0))*256)*256;    
                }break;
                case 27:                        //site name setting
                {
                    checkSum = (data[61]+(1-(data[61]>=0))*256) + (data[62]+(1-(data[62]>=0))*256)*256;
                }break;
                case 22:                      //space counting type2 site edit
                {
                    checkSum = (data[siz-2]+(1-(data[siz-2]>=0))*256) + (data[siz-1]+(1-(data[siz-1]>=0))*256)*256;
                }break;
                case 19:                      //blacklist
                {
                    checkSum = (data[95]+(1-(data[95]>=0))*256) + (data[96]+(1-(data[96]>=0))*256)*256;
                }break;
                case 20:
                {
                    int len = 0;
                    for(int i=0;i<1024; i++)
                    {
                        if((data[i]+(1-(data[i]>=0))*256) == 205 && i>10)
                        {
                            len = i;
                            break;
                        }
                    }
                    len = 181;
                    checkSum = (data[len-2]+(1-(data[len-2]>=0))*256) + (data[len-1]+(1-(data[len-1]>=0))*256)*256;
                }break;
                case 31:
                {
                    checkSum = (data[34]+(1-(data[34]>=0))*256) + (data[35]+(1-(data[35]>=0))*256)*256;
                }break;
                case 34:
                {   
                    checkSum = (data[365]+(1-(data[365]>=0))*256) + (data[366]+(1-(data[366]>=0))*256)*256;
                }break;
                case 33:
                {
                    checkSum = (data[127]+(1-(data[127]>=0))*256) + (data[128]+(1-(data[128]>=0))*256)*256;
                }break;
                case 48:
                {
                    checkSum = (data[40]+(1-(data[40]>=0))*256) + (data[41]+(1-(data[41]>=0))*256)*256;
                }break;
                case 49:
                {
                    checkSum = (data[348]+(1-(data[348]>=0))*256) + (data[349]+(1-(data[349]>=0))*256)*256;
                }break;
                case 51:
                {
                    checkSum = (data[357]+(1-(data[357]>=0))*256) + (data[358]+(1-(data[358]>=0))*256)*256;
                }break;
                default:
                {
                } break;
            }
        }break;
        default:
        {
            
        }
        break;
    }
    
}

time_t DashouParser::char_to_time_t(unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6)
{
    tm time_and_date;
    time_and_date.tm_year = data1 + 100;
    time_and_date.tm_mon = data2 - 1;
    time_and_date.tm_mday = data3;
    time_and_date.tm_hour = data4;
    time_and_date.tm_min = data5;
    time_and_date.tm_sec = data6;
    time_t datetime = mktime(&time_and_date);
    if(std::difftime(datetime, Reference_date) < 0) return Reference_date;
    return datetime;
};

std::string DashouParser::Encoding_ASCII_GetString(char *data, int index, int count)
{
    std::string stream = "";
    for (int i = index; i < index + count; i++)
    {
        stream += data[i];
    }
    return stream;
};
