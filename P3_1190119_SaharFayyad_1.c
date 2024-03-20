//sahar fayyad 1190119 //sec 1 //project 3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int re = 0;//for read function
int s = 0;//for save function

int count = 0;
int table_size = 0;//table size for hashing
double load;//load factor

struct avl_node;
typedef struct avl_node *avl_t;

struct avl_node {
    char name_pateint[20];
    char gen[10];
    char doa[20];
    char dateob[20];
    char illness[20];
    char city[20];
    char type_blood[20];

    avl_t left;
    avl_t right;
    int height;
};


//avl tree functions
avl_t MakeEmpty(avl_t t);

int get_height(avl_t t);

int max(int x, int y);

avl_t singleRotateLeft(avl_t a);

avl_t singleRotateRight(avl_t b);

avl_t doubleRotateLeft(avl_t x);

avl_t doubleRotateRight(avl_t x);

avl_t findMin(avl_t t);

int get_balance(avl_t t);


avl_t insert(avl_t t, char a[], char b[], char c[], char d[], char e[], char f[], char g[]);

avl_t find(avl_t t, char k[]);

avl_t deletedNode(avl_t t, char k[]);


avl_t read(avl_t tree);

void update(avl_t t);

void insert_from_user(avl_t t);

void list_same_illness(avl_t t, char ill[]);

void printInorder(avl_t t);

void save_to_thefile(avl_t t, FILE *f);


/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/


typedef struct patient {
    char name[100];
    char ge[10];
    char dofa[20];
    char dob[20];
    char ill[20];
    char address[20];
    char t_b[20];


} patient;

typedef patient *hash;
hash *hash_table;

//hashing function
int isPrime(int n);

int nextPrime(int n);

int hash_h(char *e);

int hash_func(char *k, int i);

patient *create_patient(char *name, char *b, char *c, char *d, char *e, char *f, char *g);

void rehash();

void insert_hash(patient *p);

int serach(char *k);

int delet_hash(char *k);

void disply_hash();

void disply_hash_infile();

void read_hash();


//driver main for hashing
void main_hash() {

    hash_table = malloc(sizeof(hash) * table_size);
    for (int i = 0; i < table_size; ++i) {//initialize the hash table
        hash_table[i] = NULL;
    }

    printf("----Hash menu----\n");
    printf("1.Display Hash \n");
    printf("2.Table Size\n");
    printf("3.Used Function\n");
    printf("4.Insert A New Patient\n");
    printf("5.Search\n");
    printf("6.Delete\n");
    printf("7.Save\n");
    printf("8.Exit\n");

    read_hash();

    while (1) {

        printf("\nenter an operation\n");

        int in;
        scanf("%d", &in);

        switch (in) {

            case 1:

                disply_hash();

                break;

            case 2:

                printf("The Size Of The Hash Table is %d", table_size);

                break;

            case 3:

                printf("The Used Hash Function Is Quadratic Probing (Open Addressing)\n");
                printf("The Equation is hi(key) = [h(key) + i^2] % tableSize\n");

                break;

            case 4:
                printf("insert a new node\n");
                char a[50], b[10], c[50], d[50], e[40], f[50], g[10];
                printf("Please put the information in this order:\n");

                printf("Patient->");
                gets(a);
                gets(a);

                printf("Gender->");
                gets(b);

                printf("Date of.A->");
                gets(c);

                printf("Date of birth->");
                gets(d);

                printf("Illness->");
                gets(e);

                printf("Address(City)->");
                gets(f);

                printf("Blood Type->");
                gets(g);

                insert_hash(create_patient(a, b, c, d, e, f, g));
                disply_hash();

                break;

            case 5:
                printf("");
                char l[40];
                printf("enter the patient you want to search\n");
                gets(l);
                gets(l);
                if (serach(l) == 1) {
                    printf("");
                } else {
                    printf("not found!!!!!\n");
                }

                break;

            case 6:

                printf("");
                char t[40];
                printf("enter the patient you want to delete\n");
                gets(t);
                gets(t);
                if (delet_hash(t) == 1) {
                    printf("");
                } else {
                    printf("not found!!!!!!");
                }

                break;

            case 7:

                printf("check the output file");
                disply_hash_infile();

                break;

            case 8:

                exit(0);

                break;

            default:

                printf("choose from 1 to 8 only please :)");

                break;
        }

    }


}




/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/




//driver main avl tree
int main() {


    printf("-----Patient Information -----\n");
    printf("1.Read from the file\n");
    printf("2.Insert a new Patient\n");
    printf("3.Find a Patient\n");
    printf("4.List all Patient\n");
    printf("5.List all Patient with the same Illness\n");
    printf("6.Delete a Patient\n");
    printf("7.Save to the file\n");
    printf("8.Hash Menu\n");
    printf("9.Exit\n");

    avl_t tree = NULL;
    FILE *out;


    while (1) {

        printf("\nPlease enter an operation\n");
        int op;
        scanf("%d", &op);

        switch (op) {

            case 1:

                if (re == 0) {

                    tree = read(tree);
                    printf("done");

                } else {

                    printf("you already read the file !!!");

                }

                break;

            case 2:

                if (re == 0) {

                    printf("Please read the file first !!!");

                } else {

                    insert_from_user(tree);

                }
                break;

            case 3:

                if (re == 0) {

                    printf("Please read the file first !!!");

                } else {
                    char r[40];
                    printf("Please enter the patient you want find \n");
                    gets(r);
                    gets(r);
                    avl_t t;
                    t = NULL;
                    t = find(tree, r);
                    if (t != NULL) {
                        printf("the patient was found \n");

                        update(t);

                    } else {
                        printf("not found!!!!!!");
                    }

                }

                break;

            case 4:

                if (re == 0) {

                    printf("Please enter the patient you want find \n");

                } else {

                    printInorder(tree);

                }

                break;

            case 5:

                if (re == 0) {

                    printf("Please enter the patient you want find \n");

                } else {

                    char g[40];
                    printf("Please enter the illness you want to list \n");
                    gets(g);
                    gets(g);

                    list_same_illness(tree, g);

                }

                break;

            case 6 :

                if (re == 0) {

                    printf("Please enter the patient you want find \n");

                } else {

                    char k[40];
                    printf("Please enter the patient you want to delete\n");
                    gets(k);
                    gets(k);

                    avl_t t;
                    t = NULL;
                    t = find(tree, k);
                    if (t != NULL) {
                        tree = deletedNode(tree, k);
                        printf("deleted");
                    } else {
                        printf("sorry did not found!!");
                    }

                }
                break;

            case 7:

                if (re == 0) {

                    printf("Please read the file first!!!");

                } else {

                    out = fopen("C:\\Users\\user\\CLionProjects\\P3_1190119_SaharFayyad_1.c\\patients_hash.data", "a");
                    save_to_thefile(tree, out);
                    fclose(out);
                    printf("check the output file please\n");
                }
                s++;

                break;

            case 8:

                if (s == 0) {//if the user did not save the file then i save it before moving to hash table part

                    out = fopen("C:\\Users\\user\\CLionProjects\\P3_1190119_SaharFayyad_1.c\\patients_hash.data", "a");
                    save_to_thefile(tree, out);
                    fclose(out);
                    main_hash();

                } else {

                    main_hash();

                }


                break;

            case 9:
                exit(1);
                break;

            default:
                printf("choice from 1 to 9 please");
                break;


        }

    }


    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//check if the avl tree is null
avl_t MakeEmpty(avl_t t) {
    if (t != NULL) {
        MakeEmpty(t->left);
        MakeEmpty(t->right);
        free(t);
    }
    return NULL;
}

//get the height of the avl tree
int get_height(avl_t t) {
    if (t == NULL)
        return -1;
    else
        return t->height;

}

//return the max in the avl tree
int max(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}

//Single left rotation:

avl_t singleRotateLeft(avl_t a) {
    avl_t b;
    b = a->right;// The right child b of a node a becomes a's parent.
    a->right = b->left;// The left child T2 of b, if any, becomes the right child of a.
    b->left = a;// a becomes the left child of b.

    //check the height again after rotation
    a->height = 1 + max(get_height(a->left), get_height(a->right));
    b->height = 1 + max(get_height(a), get_height(b->right));

    return b;

}

// Single right rotation
avl_t singleRotateRight(avl_t b) {
    avl_t a;
    a = b->left; //The left child a of a node b becomes b's parent.
    b->left = a->right;//The right child T2 of a, if any, becomes the left child of b
    a->right = b;// b becomes the right child of a.

    //    //check the height again after rotation
    b->height = 1 + max(get_height(b->right), get_height(b->left));
    a->height = 1 + max(get_height(b), get_height(a->left));

    return a;
}

//a left rotation followed by a right rotation.
avl_t doubleRotateLeft(avl_t x) {
    x->left = singleRotateLeft(x->left);
    return singleRotateRight(x);
}

//a right rotation followed by a left rotation.
avl_t doubleRotateRight(avl_t x) {
    x->right = singleRotateRight(x->right);
    return singleRotateLeft(x);
}

//find the min node in the tree
avl_t findMin(avl_t t) {
    if (t == NULL) {
        return NULL;
    }
    if (t->left == NULL) {
        return t;
    } else {
        return findMin(t->left);
    }
}


//check if the tree is balance
int get_balance(avl_t t) {
    if (t == NULL)
        return 0;
    else
        return get_height(t->left) - get_height(t->right);
}


/**********************************************************************************************************************/

// Recursive function to insert a key
avl_t insert(avl_t t, char a[], char b[], char c[], char d[], char e[], char f[], char g[]) {

    if (t == NULL) { // 1. Perform the normal avl insertion
        t = malloc(sizeof(struct avl_node));
        if (t == NULL) {
            printf("out of the space!!!");
        } else {
            strcpy(t->name_pateint, a);
            strcpy(t->gen, b);
            strcpy(t->doa, c);
            strcpy(t->dateob, d);
            strcpy(t->illness, e);
            strcpy(t->city, f);
            strcpy(t->type_blood, g);

            t->height = 0;
            t->left = t->right = NULL;
        }
    } else if (strcmp(a, t->name_pateint) < 0) {
        t->left = insert(t->left, a, b, c, d, e, f, g);
        //check the balance
        if (get_height(t->left) - get_height(t->right) >= 2) {
            if (strcmp(a, t->left->name_pateint) < 0)
                t = singleRotateRight(t);
            else
                t = doubleRotateLeft(t);
        }
    } else if (strcmp(a, t->name_pateint) > 0) {
        t->right = insert(t->right, a, b, c, d, e, f, g);
        //check the balance
        if (get_height(t->right) - get_height(t->left) >= 2) {
            if (strcmp(a, t->right->name_pateint) > 0)
                t = singleRotateLeft(t);
            else
                t = doubleRotateRight(t);
        }
    }

    t->height = 1 + max(get_height(t->right), get_height(t->left));

    return t;
}


//find function to find a node
avl_t find(avl_t t, char k[]) {
    if (t == NULL)
        return NULL;
    if (strcmp(k, t->name_pateint) < 0)
        return (find(t->left, k));
    if (strcmp(k, t->name_pateint) > 0)
        return (find(t->right, k));
    else
        return t;
}


avl_t deletedNode(avl_t t, char k[30]) {
    if (t == NULL)
        return t;

    //find the node to delet
    if (strcmp(k, t->name_pateint) < 0)
        t->left = deletedNode(t->left, k);
    else if (strcmp(k, t->name_pateint) > 0)
        t->right = deletedNode(t->right, k);


    else {

        if ((t->left == NULL) || (t->right == NULL)) {
            avl_t temp = t->left ? t->left : t->right;

            if (temp == NULL) {//no children
                temp = t;
                t = NULL;
            } else {
                *t = *temp;
                free(temp);
            }
        } else {//have 2 children

            avl_t temp = findMin(t->right);
            strcpy(t->name_pateint, temp->name_pateint);
            strcpy(t->gen, temp->gen);
            strcpy(t->doa, temp->doa);
            strcpy(t->dateob, temp->dateob);
            strcpy(t->illness, temp->illness);
            strcpy(t->city, temp->city);
            strcpy(t->type_blood, temp->type_blood);

            t->right = deletedNode(t->right, temp->name_pateint);

        }

    }

    //if the tree contain one node then return it
    if (t == NULL)
        return t;

    //update the height of the node
    t->height = 1 + max(get_height(t->left), get_height(t->right));

    //check if the node become unbalanced
    int balance = get_balance(t);


    //if the tree unbalanced

    //left - left rotate
    if (balance > 1 && get_balance(t->left) >= 0) {
        return singleRotateRight(t);
    }

    //left - right rotate
    if (balance > 1 && get_balance(t->left) < 0) {
        t->left = singleRotateLeft(t->left);
        return singleRotateRight(t);
    }

    //right - right rotate
    if (balance < -1 && get_balance(t->right) <= 0) {
        return singleRotateLeft(t);
    }

    //right - left rotate
    if (balance < -1 && get_balance(t->right) > 0) {
        t->right = singleRotateRight(t->right);
        return singleRotateLeft(t);
    }


    return t;
}

/**********************************************************************************************************************/


//read from file and insert to avl tree
avl_t read(avl_t tree) {
    char buffer[500], all[500], patient[20], gender[10], dateof_a[30], dob[30], ill[50], address[30], blood_type[10];
    char *token;
    FILE *file = fopen("C:\\Users\\user\\CLionProjects\\P3_1190119_SaharFayyad_1.c\\patients.txt", "r");
    while (!feof(file)) {
        fgets(all, sizeof(all), file);

        token = strtok(all, "\n");
        strcpy(buffer, token);
        token = strtok(buffer, "#");
        strcpy(patient, token);
        token = strtok(NULL, "#");
        strcpy(gender, token);
        token = strtok(NULL, "#");
        strcpy(dateof_a, token);
        token = strtok(NULL, "#");
        strcpy(dob, token);
        token = strtok(NULL, "#");
        strcpy(ill, token);
        token = strtok(NULL, "#");
        strcpy(address, token);
        token = strtok(NULL, "#");
        strcpy(blood_type, token);
        tree = insert(tree, patient, gender, dateof_a, dob, ill, address, blood_type);
    }
    fclose(file);
    re++;
    return tree;
}

//in case 2 :function to allowed the user to enter to the tree
void insert_from_user(avl_t t) {


    char a[20], b[10], c[30], d[30], e[30], f[30], g[30];
    printf("please put the information in this order");

    //enter the information by the user
    printf("\npatient name->");
    gets(a);
    gets(a);

    printf("gender->");
    gets(b);

    printf("date of admission->");
    gets(c);

    printf("date of birth->");
    gets(d);

    printf("illness ->");
    gets(e);

    printf("address->");
    gets(f);

    printf("blood type->");
    gets(g);

    t = insert(t, a, b, c, d, e, f, g);

}

//function to allowed the user to update after find the a specific key and the user choose
//what he want to update
void update(avl_t t) {

    printf("1.Patient Name\n");
    printf("2.Gender\n");
    printf("3.Date Of Admission\n");
    printf("4.Date Of Birth\n");
    printf("5.Illness\n");
    printf("6.Address(City)\n");
    printf("7.Blood Type\n");

    char a[30], b[20], c[20], d[20], e[20], f[20], g[20];


    while (1) {
        printf("\nChoose the type you want to update\n");
        printf("\nChoose from 1 to 7 only and other number to out from update\n");


        int x;
        scanf("%d", &x);

        switch (x) {

            case 1:
                printf("Patient Name :");
                gets(a);
                gets(a);
                strcpy(t->name_pateint, a);
                printInorder(t);

                continue;


            case 2:
                printf("Gender :");
                gets(b);
                gets(b);
                strcpy(t->gen, b);
                printInorder(t);

                continue;


            case 3:

                printf("Date Of Admission :");
                gets(c);
                gets(c);
                strcpy(t->doa, c);
                printInorder(t);

                continue;

            case 4:

                printf("Date Of Birth :");
                gets(d);
                gets(d);
                strcpy(t->dateob, d);
                printInorder(t);

                continue;

            case 5:
                printf("Illness :");
                gets(e);
                gets(e);
                strcpy(t->illness, e);
                printInorder(t);

                continue;

            case 6:
                printf("Address (city) :");
                gets(f);
                gets(f);
                strcpy(t->city, f);
                printInorder(t);

                continue;

            case 7:
                printf("Blood Type :");
                gets(g);
                gets(g);
                strcpy(t->type_blood, g);
                printInorder(t);

                continue;

            default:
                break;

        }
        break;

    }

}


//list the patient with same illness
void list_same_illness(avl_t t, char ill[]) {
    if (t != NULL) {
        list_same_illness(t->left, ill);
        if (strcmp(t->illness, ill) == 0) {
            printf("The Infected Persons is :%s\n", t->name_pateint);
        }
        list_same_illness(t->right, ill);
    }
}


//print in lexicographic order
void printInorder(avl_t t) {
    if (t != NULL) {
        printInorder(t->left);
        printf("patient name:%s || gender:%s || date of .adm:%s || date of birth:%s "
               "|| illness:%s || city:%s || blood type:%s\n",
               t->name_pateint, t->gen, t->doa, t->dateob, t->illness, t->city, t->type_blood);
        printInorder(t->right);
    }
}

//save to the file
void save_to_thefile(avl_t t, FILE *f) {

    if (t != NULL) {
        save_to_thefile(t->left, f);
        fprintf(f, "%s||%s||%s||%s||%s||%s||%s\n",
                t->name_pateint, t->gen, t->doa, t->dateob, t->illness, t->city, t->type_blood);
        save_to_thefile(t->right, f);
        table_size++;
    }

}




/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/


//function to read from a file and insert to hash table
void read_hash() {
    char buff[500], buffer[500], patient[20], gender[10], dateof_a[30], dob[30], ill[50], address[30], blood_type[10];
    char *token;
    FILE *file = fopen("C:\\Users\\user\\CLionProjects\\P3_1190119_SaharFayyad_1.c\\patients_hash.data", "r");

    while (fgets(buff, sizeof(buff), file) != NULL) {


        token = strtok(buff, "\n");
        strcpy(buffer, buff);
        token = strtok(buffer, "||");
        strcpy(patient, token);
        token = strtok(NULL, "||");
        strcpy(gender, token);
        token = strtok(NULL, "||");
        strcpy(dateof_a, token);
        token = strtok(NULL, "||");
        strcpy(dob, token);
        token = strtok(NULL, "||");
        strcpy(ill, token);
        token = strtok(NULL, "||");
        strcpy(address, token);
        token = strtok(NULL, "||");
        strcpy(blood_type, token);


        insert_hash(create_patient(patient, gender, dateof_a, dob, ill, address, blood_type));
    }


    fclose(file);


}

//check if the the number is prime
int isPrime(int n) {
    int i;
    int a = n / 2;
    for (i = 3; i <= a; i++)
        if (n % i == 0) return 0;
    return 1;
}

//find the prime number
int nextPrime(int n) {
    int num = n + 1;  // parameter n is even, hence +1 to make it odd.
    while (!isPrime(num)) num += 2;
    return num;
}

//h[key] = k % table_size
int hash_h(char *e) {
    int g = 0;
    for (int j = 0; j < table_size; j++) {
        g += e[j];
    }
    return g % table_size;
}

//return the equation in Quadratic Probing
int hash_func(char *k, int i) {
    int j = hash_h(k);
    return (j + i * i) % table_size;
}

//copy the information to the hash table
patient *create_patient(char *name, char *b, char *c, char *d, char *e, char *f, char *g) {
    patient *p = malloc(sizeof(patient));

    strcpy(p->name, name);
    strcpy(p->ge, b);
    strcpy(p->dofa, c);
    strcpy(p->dob, d);
    strcpy(p->ill, e);
    strcpy(p->address, f);
    strcpy(p->t_b, g);

    return p;
}

//rehash function to reinsert the information when the load = 0.75 from the table
void rehash() {

    int x = table_size;

    table_size = nextPrime(table_size * 2);

    hash *table = hash_table;

    hash_table = malloc(table_size * sizeof(hash));

    for (int i = 0; i < table_size; ++i) {
        hash_table[i] = NULL;
    }

    count = 0;
    for (int i = 0; i < x; ++i) {
        if (table[i])
            insert_hash(table[i]);
    }
}

//function to insert the information to the hash table
void insert_hash(patient *p) {

    load = (double) (count + 1.0) / table_size;

    if (load >= 0.75) {//check the load
        rehash();
    }

    int j = 0;

    while (j < table_size) {
        int i = hash_func(p->name, j);
        if (hash_table[i] == NULL) {
            hash_table[i] = p;
            break;
        }
        j++;
    }
    count++;


}


//print the hash table
void disply_hash() {

    for (int i = 0; i < table_size; i++) {

        printf("\n %d\t", i);
        if (hash_table[i] == NULL) {
            printf("---");
        } else {
            printf("%s %s %s %s %s %s %s ", hash_table[i]->name, hash_table[i]->ge, hash_table[i]->dofa,
                   hash_table[i]->dob, hash_table[i]->ill, hash_table[i]->address, hash_table[i]->t_b);
        }

    }

}

//function to search in the hash table
int serach(char *k) {
    int i = 0;

    while (i < table_size) {
        int key = hash_func(k, i);
        if (hash_table[key] != NULL) {
            if (strcmp(hash_table[key]->name, k) == 0) {
                printf("the patient %s found\n", k);
                return 1;
                break;
            }
        }
        i++;
    }
    return 0;

}

//delete a node in the hash table
int delet_hash(char *k) {
    int key;
    int i = 0;


    while (i < table_size) {
        key = hash_func(k, i);
        if (hash_table[key] != NULL) {

            if (strcmp(hash_table[key]->name, k) == 0) {
                printf("the patient %s deleted\n", hash_table[key]->name);
                free(hash_table[key]);
                hash_table[key] = NULL;
                count--;
                return 1;
                break;
            }
        }
        i++;
    }
    load = (double) (count) / table_size;

    return 0;
}

//print the hash table to the file
void disply_hash_infile() {

    FILE *fp;
    fp = fopen("C:\\\\Users\\\\user\\\\CLionProjects\\\\P3_1190119_SaharFayyad_1.c\\\\patients_hash.data", "w");

    for (int i = 0; i < table_size; i++) {

        fprintf(fp, "\n %d\t", i);
        if (hash_table[i] == NULL) {
            fprintf(fp, "---");
        } else {
            fprintf(fp, "%s %s %s %s %s %s %s ", hash_table[i]->name, hash_table[i]->ge, hash_table[i]->dofa,
                    hash_table[i]->dob, hash_table[i]->ill, hash_table[i]->address, hash_table[i]->t_b);
        }

    }

    fclose(fp);
}
