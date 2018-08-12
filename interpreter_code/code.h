#include <vector>
#include <string>
#include <iostream>

struct memory
{
    using bitset_type = std::vector<bool>;


    memory()
    {
        value.push_back(false);
        side = false;
        index = 0;
    }

    void print() const
    {
        std::cout << "memory: ";
        for (auto b : value)
        {
            std::cout << b;
        }
        std::cout << "\nregister: " << side << "\nindex: " << index << "\nresult: " << read_bool_vec(value).c_str() << std::endl;
    }

    bitset_type value;
    bool side;
    size_t index;

    void move()
    {
        if (side)
        {
            ++index;
            if (value.size() == index)
            {
                value.push_back(false);
            }
        }
        else
        {
            if(index!=0)
            {
                --index;
            }
        }
    }

    void flip()
    {
        side = !side;
    }

    void swap()
    {
        bool oldside = side;
        side = value[index];
        value[index] = oldside;
    }


    static std::string read_bool_vec(bitset_type const& a)
    {
        std::string ret;
        unsigned char curchar = 0b00000000;
        int i = 8;
        for (auto v : a)
        {
            curchar = curchar << 1;
            if (v)
            {
                curchar |= 0b00000001;
            }
            
            --i;
            if (i == 0)
            {
                ret.push_back(curchar);
                curchar = 0b00000000;
                i = 8;
            }
        }
        if (i != 8)
        {
            ret.push_back(curchar << i);
        }
        ret.push_back('\0');
        return ret;
    }
};


struct instructions
{
    
    enum class ops
    {
        move, flip, swap, loop
    };


    using instructionset_type = std::vector<ops>;

    instructions(std::string const& a)
    {
        for(auto i:a)
        {
            switch(i)
            {
                case('+'):
                data.push_back(ops::move);
                break;
                case('!'):
                data.push_back(ops::flip);
                break;
                case('='):
                data.push_back(ops::swap);
                break;
                case('/'):
                data.push_back(ops::loop);
                break;
            }
        }
    }

    instructionset_type data;

    void recede(size_t& i) const
    {
        while(i!=0 && data[i]!=ops::loop)
        {
            --i;
        }
    }

    void proceed(size_t& i) const
    {
        while(i!=data.size() && data[i]!=ops::loop)
        {
            ++i;
        }
    }

    void run(memory& a) const
    {
        size_t i = 0;
        while(i!=data.size())
        {
            switch(data[i])
            {
            case(ops::move):
                a.move();
                break;
            case(ops::flip):
                a.flip();
                break;
            case(ops::swap):
                a.swap();
                break;
            case(ops::loop):
                if(a.side)
                {
                    proceed(i);
                    if(i==data.size())
                    {
                        return;
                    }
                }
                else
                {
                    recede(i);
                    if(i == 0)
                    {
                        continue; //so that i will not be incremented
                    }
                }
                break; //i is left of on a loop, so the increment will place it on the next instruction.
            }
            ++i;
        }
    }
};


void run(std::string a)
{
    memory m;
    instructions i{a};
    i.run(m);
    m.print();
}