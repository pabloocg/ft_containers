#include "tests/list_test.cpp"
#include "tests/list_sys.cpp"
#include "tests/queue_test.cpp"
#include "tests/queue_sys.cpp"
#include "tests/stack_test.cpp"
#include "tests/stack_sys.cpp"
#include "tests/vector_test.cpp"
#include "tests/vector_sys.cpp"
#include "tests/map_test.cpp"
#include "tests/map_sys.cpp"
#include "tests/multimap_test.cpp"
#include "tests/multimap_sys.cpp"
#include "tests/set_sys.cpp"
#include "tests/set_test.cpp"
#include "tests/multiset_sys.cpp"
#include "tests/multiset_test.cpp"

int main(int argc, char **argv)
{
    (void)argc;
    if (!strcmp(argv[1], "list_test"))
        list_test();
    else if (!strcmp(argv[1], "list_sys"))
        list_sys();
    else if (!strcmp(argv[1], "queue_test"))
        queue_test();
    else if (!strcmp(argv[1], "queue_sys"))
        queue_sys();
    else if (!strcmp(argv[1], "stack_test"))
        stack_test();
    else if (!strcmp(argv[1], "stack_sys"))
        stack_sys();
    else if (!strcmp(argv[1], "vector_test"))
        vector_test();
    else if (!strcmp(argv[1], "vector_sys"))
        vector_sys();
    else if (!strcmp(argv[1], "map_test"))
        map_test();
    else if (!strcmp(argv[1], "map_sys"))
        map_sys();
    else if (!strcmp(argv[1], "multimap_test"))
        multimap_test();
    else if (!strcmp(argv[1], "multimap_sys"))
        multimap_sys();
    else if (!strcmp(argv[1], "set_test"))
        set_test();
    else if (!strcmp(argv[1], "set_sys"))
        set_sys();
    else if (!strcmp(argv[1], "multiset_test"))
        multiset_test();
    else if (!strcmp(argv[1], "multiset_sys"))
        multiset_sys();
    else
        std::cout << "Usage ./ft_containers <all | list | queue | stack | vector | map | multimap>" << std::endl;
    return (0);
}