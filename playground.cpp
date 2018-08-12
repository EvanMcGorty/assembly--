#include"interpreter_code/code.h"
#include"explanation.h"

int main()
{
    std::cout << explanation() << '\n';
    
    while(true)
    {
        std::cout << "enter program, press enter twice in a row to execute:\n" << std::flush;
        
        std::string to_run;

        while(true)
        {
            std::string a;
            std::getline(std::cin,a);
            if(a == "")
            {
                break;
            }
			to_run.append(std::move(a));
        }

        run(to_run);

    }

    system("pause");
}