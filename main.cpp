#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include "lua.hpp"

#include "external_libs/simplepot/SimpleOpt.h"
#include "lua_execution.h"

#define DEFAULT_LUA_ITER_NUM    10
#define DEFAULT_EXECUTION_TIMES 10


// An enum for all the option types
enum {
    OPT_HELP,
    OPT_LUA_SCRIPT_FILE,
    OPT_LUA_ITER_NUM,
    OPT_LUA_EXEC_TIMES
    };


static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << " -l lua_script.lua -i lua_iterations -e exec_iter\n"
              << "Options:\n"
              << "\t-h,--help\tShow this help message\n"
              << "\t-l,--lua FILE\tSpecify the path to .lua file to be loaded\n"
              << "\t-i INT \t\tSpecify the number of internal iterations for the lua file\n"
              << "\t-e INT \t\tSpecify the number of external iterations for the lua file"
              << std::endl;
}

/* these are the argument types:
   SO_NONE --    no argument needed
   SO_REQ_SEP -- single required argument
   SO_MULTI --   multiple arguments needed
*/
static CSimpleOpt::SOption parser_options[] =
{
    { OPT_HELP,                 "-?",           SO_NONE     },
    { OPT_HELP,                 "-h",           SO_NONE     },
    { OPT_HELP,                 "--help",       SO_NONE     },
    { OPT_LUA_SCRIPT_FILE,      "-l",           SO_REQ_SEP  },
    { OPT_LUA_SCRIPT_FILE,      "--lua",        SO_REQ_SEP  },
    { OPT_LUA_ITER_NUM,         "-i",           SO_REQ_SEP  },
    { OPT_LUA_EXEC_TIMES,       "-e",           SO_REQ_SEP  },
    SO_END_OF_OPTIONS
};

static struct SParserOptions {
    SParserOptions() : lua_main_method("main"),
                       lua_iter_num(DEFAULT_LUA_ITER_NUM),
                       lua_exec_times(DEFAULT_EXECUTION_TIMES) {}
    std::string lua_file;
    std::string lua_main_method;
    unsigned long lua_iter_num;
    unsigned long lua_exec_times;

//    std::ostream & operator<<(std::ostream & Str, SParserOptions const & v) {
//        Str << "lua_file:\t\t" << v.lua_file << std::endl;
//        Str << "lua_main_method:\t" << v.lua_main_method << std::endl;
//        Str << "lua_iter_num:\t" << v.lua_iter_num << std::endl;
//        Str << "lua_exec_times:\t" << v.lua_exec_times << std::endl;
//        // print something from v to str, e.g: Str << v.getX();
//        return Str;
//    }
} SParserOptions;

static int parse_options(int argc,
                         char *argv[],
//                         SParserOptions* po,
                         std::unordered_map<std::string, int> &params)
{

    CSimpleOpt args(argc, argv, parser_options);

    while (args.Next())
    {
        if (args.LastError() == SO_SUCCESS)
        {
            // handle option: use OptionId(), OptionText() and OptionArg()
            switch (args.OptionId())
            {
                case OPT_HELP:
                {
                    show_usage(argv[0]);
                    return -1;
                }
                case OPT_LUA_SCRIPT_FILE:
                {
                    SParserOptions.lua_file = args.OptionArg();
                    break;
                }
                case OPT_LUA_EXEC_TIMES:
                {
                    SParserOptions.lua_exec_times = strtoul(args.OptionArg(), NULL, 10);
                    break;
                }
                case OPT_LUA_ITER_NUM:
                {
                    SParserOptions.lua_iter_num = strtoul(args.OptionArg(), NULL, 10);
                    break;
                }
                default:
                {
                    show_usage(argv[0]);
                    return -1;
                }
            }
        }
        else
        {
            // handle error: see ESOError enums
            show_usage(argv[0]);
            return -1;
        }
    } // end of while loop

    if ( SParserOptions.lua_file == "" ) {
        printf("Invalid combination of parameters you must add -l with lua script file \n");
        show_usage(argv[0]);
        return -1;
    }
}

int main(int argc, char* argv[])
{
    std::unordered_map<std::string, int> params;

    if ( parse_options(argc, argv, params) != 0)
    {
        exit(-1);
    }

    std::cout << "Running LUA bm with the following params:" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "LUA script file:\t\t" << SParserOptions.lua_file << std::endl;
//    std::cout << "lua_main_method:\t" << SParserOptions.lua_main_method << std::endl;
    std::cout << "LUA internal iterations #:\t" << SParserOptions.lua_iter_num << std::endl;
    std::cout << "External LUA calls:\t\t" << SParserOptions.lua_exec_times << std::endl;

//    std::cout << "Calling lua!" << std::endl;
//
//    f(5,6);

//    lua_State *state = luaL_newstate();
//    lua_close(state);
    return 0;
}