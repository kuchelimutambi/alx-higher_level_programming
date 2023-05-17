#include <Python.h>
#include <stdio.h>
<<<<<<< HEAD
/**
 * print_python_list_info - print python
 * @p: input
 */
void print_python_list_info(PyObject *p)
{
	unsigned int l_idx;
	unsigned int len;
	unsigned int allocated;
	PyTypeObject *type;
	const char *name;

	if (p == NULL)
		return;

	len = (unsigned int) PyList_Size(p);
	allocated = (unsigned int) ((PyListObject *)p)->allocated;
	printf("[*] Size of the Python List = %d\n", len);
	printf("[*] Allocated = %d\n", allocated);

	for (l_idx = 0; l_idx < len; l_idx++)
	{
		type = PyList_GET_ITEM(p, l_idx)->ob_type;
		name = type->tp_name;
		printf("Element %d: %s\n", l_idx, name);
	}
=======
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
>>>>>>> 575e2c6cf168f3939bf373ce30d6a4679fc076c6
}
