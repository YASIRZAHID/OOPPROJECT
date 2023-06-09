#include <iostream>  
#include <string.h>  
#include <stdlib.h>
#include <iomanip> 
#include <cmath>
using namespace std; 
    
struct STACK{  
    int TOP;  
    unsigned DATA;      // using unsigned because we have to store positive integers and chars
    int* ARRAY;  
};  
  
  
int IS_EMPTY(struct STACK* STACK){  
    return STACK->TOP == -1 ;  // top is -1 when array is empty
}  
  
char REMOVE_TOPMOST(struct STACK* STACK){  
    if (!IS_EMPTY(STACK)){
    	return STACK->ARRAY[STACK->TOP--] ;  // pops the upper val from STACK and decrements top
	}  
    return 'N';  // JUST BCZ WE MUST RETURN
}  
void VALUE_INTO_STACK(struct STACK* STACK, char INCOMING){  // PUSHES VALUE INTO STACK
    STACK->ARRAY[++STACK->TOP] = INCOMING;  
}  
struct STACK* CREATE_STACK( unsigned DATA ){  
    struct STACK* STACK = (struct STACK*) malloc(sizeof(struct STACK));  

    if (!STACK){ // WHILE CREATION
		return NULL;  
    }
    STACK->TOP = -1;  
    STACK->DATA = DATA;  
    STACK->ARRAY = (int*) malloc(STACK->DATA * sizeof(int));  // MALLOC IS FUNCTION THAT MAKES A CHUNK OF UNALLOCATED MEMORY RETURNING ADDRESS OF THE FIRST BYTE 
  
    if (!STACK->ARRAY){
    	return NULL;
	} 
		  
    return STACK;  
}    
    
int WHAT_IS_THIS(char* ONE_BY_ONE_ENTRY){  
    struct STACK* STACK = CREATE_STACK(strlen(ONE_BY_ONE_ENTRY));  // CREATING STACK EQUAL IN SIZE TO ENTERERED EXPRESSION
    int LOOP;  
  
    if (!STACK){
    	return -1;
	} 
		  
    
    for (LOOP = 0; ONE_BY_ONE_ENTRY[LOOP]!=0 ; ++LOOP){  
          
        if (isdigit(ONE_BY_ONE_ENTRY[LOOP])){  // IF NUMBER PASS VALUE TO THE STACK
            VALUE_INTO_STACK(STACK, ONE_BY_ONE_ENTRY[LOOP] - '0');  
  	    }else{  
            int val1 = REMOVE_TOPMOST(STACK);  
            int val2 = REMOVE_TOPMOST(STACK);  
            
			switch (ONE_BY_ONE_ENTRY[LOOP]){  
	            case '+': 
						VALUE_INTO_STACK(STACK, val2 + val1); 
						break;  
	            case '-': 
						VALUE_INTO_STACK(STACK, val2 - val1); 
						break;  
	       	    case '*': 
						VALUE_INTO_STACK(STACK, val2 * val1); 
						break;  
	            case '/': 
						VALUE_INTO_STACK(STACK, val2/val1); 
						break; 
				case '^': 
						VALUE_INTO_STACK(STACK, pow(val2,val1));
						break; 
				default:
						cout<<"INVALID EXPRESSION";		
	        }  
        }  
    }  
    return REMOVE_TOPMOST(STACK);  
}  
   
int main(){  
//	int done=1;
//while(done==1){
//	int size=0;
//	cout<<"\nENTER THE SIZE: ";
//	cin>>size;
//    char s[size];
//    cout<<"\nENTER THE EXPRESSION: ";
//    cin.ignore();
	char s[]="56+";
//    cin.get(s,size);
    cout<<"\nPOSTFIX EVALUATION :     "<< WHAT_IS_THIS(s);    
//}
}
