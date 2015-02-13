// #include <bison/parser.hpp>

#include <aq/parser/SQLParser.h>
#include <aq/util/QueryReader.h>
#include <iostream>

int main(int argc, char ** argv)
{

    auto fn = [] (std::string query) {

        if (query == "")
            return;

        std::cout << query << std::endl;

        {
            aq::tnode * nodes;
            SQLParse(query.c_str(), nodes);
            std::cout << *nodes << std::endl;
        }

    };

    for (int i = 1; i < argc; i++)
    {
        fn(argv[i]);
    }

    aq::QueryReader reader(std::cin);
    while (!reader.eos())
    {
        fn(reader.next());
    }

    return 0;
}
