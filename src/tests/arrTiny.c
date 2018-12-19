int main() {
    int a;
    int array[10];
    array[1] = array[1];
    a = array[1];
    a = array[1+a];
    return 0;
}
