#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(){
void *handle;
int (*add)(int, int), (*sub)(int, int), (*mul)(int, int), (*div)(int, int);
char *error;

handle = dlopen("./lib/libdynamic.so", RTLD_LAZY);
if(!handle){
	fputs (dlerror(), stderr);
	exit(1);
}
add = dlsym(handle, "add");
if((error = dlerror()) !=NULL){
	fprintf(stderr, "%s", error);
	exit(1);
}
sub = dlsym(handle, "sub");
if((error = dlerror()) !=NULL){
        fprintf(stderr, "%s", error);
        exit(1);
}
mul = dlsym(handle, "mul");
if((error = dlerror()) !=NULL){
        fprintf(stderr, "%s", error);
        exit(1);
}
div = dlsym(handle, "div");
if((error = dlerror()) !=NULL){
        fprintf(stderr, "%s", error);
        exit(1);
}


int a;
a = 10;
int b;
b = 2;

printf("add : %d\n", add(a,b));
printf("sub : %d\n", sub(a,b));
printf("mul : %d\n", mul(a,b));
printf("div : %d\n", div(a,b));

dlclose(handle);
}
