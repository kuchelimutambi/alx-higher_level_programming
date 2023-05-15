#include <Python.h>
#include <stdio.h>
#include "listobject.h"
#include "object.h"

/**
 * print_python_list_info - Prints basic information about Python lists
 * @p: PyObject pointer to the Python list object
 */
void print_python_list_info(PyObject *p)
{
    unsigned int list_size, list_alloc, i;
    PyTypeObject *obj_type;

    if (p == NULL || !PyList_Check(p))
    {
        printf("Invalid Python List\n");
        return;
    }

    list_size = (unsigned int)PyList_Size(p);
    list_alloc = (unsigned int)((PyListObject *)p)->allocated;

    printf("[*] Size of the Python List = %u\n", list_size);
    printf("[*] Allocated = %u\n", list_alloc);

    for (i = 0; i < list_size; i++)
    {
        obj_type = PyList_GetItem(p, i)->ob_type;
        printf("Element %u: %s\n", i, obj_type->tp_name);
    }
}
