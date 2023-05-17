#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p) {
    Py_ssize_t size;
    Py_ssize_t i;

    if (!PyList_Check(p)) {
        printf("[*] Invalid Python List\n");
        return;
    }

    size = PyList_Size(p);

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++) {
        PyObject *item = PyList_GET_ITEM(p, i);
        const char *type = item->ob_type->tp_name;

        printf("Element %ld: %s\n", i, type);
    }
}

void print_python_bytes(PyObject *p) {
    Py_ssize_t size;
    Py_ssize_t i;
    char *bytes;

    if (!PyBytes_Check(p)) {
        printf("[.] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    bytes = PyBytes_AsString(p);

    printf("[.] bytes object info\n");
    printf("  size: %ld\n", size);

    printf("  trying string: %s\n", bytes);

    printf("  first %ld bytes: ", size < 10 ? size : 10);
    for (i = 0; i < (size < 10 ? size : 10); i++) {
        printf("%02x ", (unsigned char)bytes[i]);
    }
    printf("\n");
}

