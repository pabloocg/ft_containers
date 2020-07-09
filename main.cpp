#include "tests/list_test.cpp"
#include "tests/list_sys.cpp"
#include "tests/queue_test.cpp"
#include "tests/queue_sys.cpp"
#include "tests/stack_test.cpp"
#include "tests/stack_sys.cpp"
#include "tests/vector_test.cpp"
#include "tests/vector_sys.cpp"

int main(int argc, char **argv)
{
    (void)argc;
    if (strcmp(argv[1], "list_test"))
        list_test();
    else if (strcmp(argv[1], "list_sys"))
        list_sys();
    else if (strcmp(argv[1], "queue_test"))
        queue_test();
    else if (strcmp(argv[1], "queue_sys"))
        queue_sys();
    else if (strcmp(argv[1], "stack_test"))
        stack_test();
    else if (strcmp(argv[1], "stack_sys"))
        stack_sys();
    else if (strcmp(argv[1], "vector_test"))
        vector_test();
    else if (strcmp(argv[1], "vector_sys"))
        vector_sys();
    else
        std::cout << "Usage ./ft_containers <all | list | queue | stack | vector>" << std::endl;
    return (0);
}