enum block_type { Normal, Sub_amount_start, Sub_amount_end };

enum Relation { Great, GreatOrEqual, Less, LessOrEqual};

class Block
{
public:
    int srNo;
    block_type type;
    time_t startTime, endTime;
    int period;
    Relation relation;
    bool deduct, cross_period;
    int amount, max_amount;
    int next;
    time_t sTime;
    time_t eTime;

    Block(int sn, block_type _type, int _period, Relation _relation, bool _deduct, int _amount, int _max_amount, int _next, time_t s, time_t e)
    {
        srNo = sn;
        type = _type;
        period = _period;
        relation = _relation;
        deduct = _deduct;
        amount = _amount;
        max_amount = _max_amount;
        next = _next;
        startTime = s;
        endTime = e;
    }
};