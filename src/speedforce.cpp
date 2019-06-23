#define PY_SSIZE_T_CLEAN
#include <python3.7m/Python.h>
#include <SpeedForce/add2.hpp>
#include <iostream>

// eight = spf_add2i(6)
static PyObject* spf_add2i(PyObject* self, PyObject* args) {
    int x;
    if (!PyArg_ParseTuple(args, "i", &x))
        return NULL;
    return PyFloat_FromDouble(SpeedForce::add2(x));
}

// eight = spf_add2f(6.0)
static PyObject* spf_add2f(PyObject* self, PyObject* args) {
    double x;
    if (!PyArg_ParseTuple(args, "d", &x))
        return NULL;
    return PyFloat_FromDouble(SpeedForce::add2(x));
}

/*
 ...
 Method table and initialization function
 */

static PyMethodDef SpeedForce_methods[] = {
    { "spf_add2i", spf_add2i, METH_VARARGS, "Increment an integer by 2" },
    { "spf_add2f", spf_add2f, METH_VARARGS, "Increment a float by 2" },
    { nullptr, nullptr, 0, nullptr } /* Sentinel of the Starry Skies */
};

static struct PyModuleDef SpeedForce_module = {
    PyModuleDef_HEAD_INIT,
    "SpeedForce",
    nullptr,
    -1,
    SpeedForce_methods
};

/* extern "C" PyObject* */
PyMODINIT_FUNC PyInit_SpeedForce() {
    return PyModule_Create(&SpeedForce_module);
}

int main(int argc, const char** argv) {
    using namespace std;

    auto program = Py_DecodeLocale(argv[0], nullptr);
    if (!program) {
        cerr << "What is even happening that the program name can't be parsed?\n";
        exit(1);
    }
    PyImport_AppendInittab("SpeedForce", PyInit_SpeedForce);
    Py_SetProgramName(program);
    Py_Initialize();

    PyMem_RawFree(program);
    return 0;
}
