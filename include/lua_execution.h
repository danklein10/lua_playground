//
// Created by danklein on 8/2/16.
//

#ifndef LUA_PLAYGROUND_LUA_EXECUTION_H
#define LUA_PLAYGROUND_LUA_EXECUTION_H


class lua_execution {

};


//double f (double x, double y) {
//    double z;
//
//    /* set the scope */
//    lua_State *L = lua_open(); // lua_open is the same as luaL_newstate, see lua.h, line 287
//    luaL_openlibs(L);
//    if (luaL_dofile(L, "/home/danklein/Development/workspace/lua_playground/lua_scripts/mult.lua"))// ||
////            lua_pcall(L, 0, 0, 0)) // calling lua_pcall(L, 0, 0, 0) in order to
//    {
//        printf("error: %s", lua_tostring(L, -1));
//        return -1;
//    }
//
//    /* push functions and arguments */
//    lua_getglobal(L, "sum");  /* function to be called */
//    lua_pushnumber(L, x);   /* push 1st argument */
//    lua_pushnumber(L, y);   /* push 2nd argument */
//
//    /* do the call (2 arguments, 1 result) */
//    if (lua_pcall(L, 2, 1, 0) != 0)
//    {
//        printf("error running function `f`: %s\n",lua_tostring(L, -1));
//        return -1;
//    }
//
//    /* retrieve result */
//    if (!lua_isnumber(L, -1))
//    {
//        printf("function `f` must return a number");
//        return -1;
//    }
//
//    z = lua_tonumber(L, -1);
//    printf("Result: %f\n",z);
//
//    /* pop returned value out of stack */
//    lua_pop(L, 1);
//    lua_close(L);
//
//    return z;
//}

#endif //LUA_PLAYGROUND_LUA_EXECUTION_H
