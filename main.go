package main

// #cgo LDFLAGS: -lcuda
// #include "cuda_dl.h"
import "C"
import "fmt"


//export cuDeviceGetName
func cuDeviceGetName(name *C.char, len int, dev C.CUdevice) {
	fmt.Println("begin")
	r := C.cuDeviceGetName_dl(name, len, dev)
	if r != C.CUDA_SUCCESS {
		fmt.Println("cuDeviceGetName: " + r)
	}
}
