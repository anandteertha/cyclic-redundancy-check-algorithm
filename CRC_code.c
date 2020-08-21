#include<stdio.h>
int intput_stream[20];
int recieved_stream[20];
long int input_num;
long int recieved_num;
int divisor_stream[20];
int divisor_num;
int count_input_stream = 0;
int count_divisor_stream = 0;
int count_recievers_stream = 0;
int final_length = 0;
void get_input_stream(){
  int i,j,k,n;
  long int val = input_num;
  i=0;
  while(val!=0){
    intput_stream[i] = val%10;
    val /=10;
    i++;
  }
  count_input_stream = i;
}

void get_recievers_stream(){
  int i,j,k,n;
  long int val = recieved_num;
  i=0;
  while(val!=0){
    recieved_stream[i] = val%10;
    val /=10;
    i++;
  }
  count_recievers_stream = i;
}

void get_divisor_stream(){
  int i,j,k,n;
  long int val = divisor_num;
  i=0;
  while(val!=0){
    divisor_stream[i] = val%10;
    val /=10;
    i++;
  }
  count_divisor_stream = i;
}

void main(){
  int i,j,k,n;
  int reverse_input_stream[20];
  int reverse_divisor_stream[20];
  int test_stream[20];
  int flag = 0;
  int temp[20];
  int carry = 0;
  int iflag = 0;
  printf("\nenter a binary number as input stream: \n");
  scanf("%ld",&input_num);
  get_input_stream();
  printf("\nenter the divisor: \n");
  scanf("%d",&divisor_num);
  get_divisor_stream();
  final_length = count_divisor_stream - 1;
  i=0;
  //reversing the streams....
  while(i!=count_input_stream){
    reverse_input_stream[count_input_stream-1-i] = intput_stream[i];
    i++;
  }
  i=0;
  while(i!=count_divisor_stream){
    reverse_divisor_stream[count_divisor_stream-1-i] = divisor_stream[i];
    i++;
  }
  //appending zeros....
  for(i=0;i<final_length;i++){
    j = count_input_stream+i;
    reverse_input_stream[j] = 0;
  }
  count_input_stream += final_length;
  //making the reversed strings out original streams......
  i = 0;
  while(i!=count_input_stream){
    intput_stream[i] = reverse_input_stream[i];
    //printf("%d\t",reverse_input_stream[i]);
    i++;
  }
  //printf("\nreverse divisor stream :\n");
  i=0;
  while(i!=count_divisor_stream){
    divisor_stream[i] = reverse_divisor_stream[i];
    //printf("%d\t",reverse_divisor_stream[i]);
    i++;
  }
  /*
  printf("\n\n");
  i = 0;
  while(i!=count_input_stream){
    printf("%d\t",intput_stream[i]);
    i++;
  }
  */
  //printf("\n\n");
  /*
  i=0;
  while(i!=count_divisor_stream){
    printf("%d\t",divisor_stream[i]);
    i++;
  }
  */
  i = 0;
  while(i!=count_input_stream){
    test_stream[i] = intput_stream[i];
    i++;
  }
  //printf("\ncount divisor stream : %d",count_divisor_stream );
  //printf("\ncount input stream : %d",count_input_stream);
  //printf("\n");
  i=0;
  k=0;
  j=0;
  printf("\n");
  while(i!=count_input_stream){
    while(j!=count_divisor_stream){
      //printf("\n.....\n");
      if(j == 0 && count_input_stream - i < count_divisor_stream){
        i = count_input_stream ;
        flag = 1;
        break;
      }
      if(i!=0 || test_stream[i] != 0){
        if(test_stream[i] == divisor_stream[j]){
          test_stream[i] = 0;
          if(j==count_divisor_stream-1){
            j = 0;
            i = 0;
          }
          else{
            j++;
            break;
          }

        }
        else{
          test_stream[i] = 1;
          if(j==count_divisor_stream-1){
            j = 0;
            i = 0;
          }
          else{
            j++;

            break;
          }

        }
      }
      else{
        while(test_stream[i] == 0){
          i++;
          //flag = 1;
        }
      }
    }
    if(flag == 1)
      break;
    i++;

  }
  //printf("\n\nfinal\n");
  printf("\n\nthe remainder is :\n");
  k=0;
  while(k!=count_input_stream){
    printf("%d\t",test_stream[k]);
    k++;
  }
  printf("\n\n");

  //add the two binay numbers:
  i=0;
  carry = 0;
  printf("\n");
  while(i!=count_input_stream){
    if(test_stream[i]==intput_stream[i]){
      intput_stream[i] = 0;
    }
    else{ //(test_stream[i] != intput_stream[i] ){
      intput_stream[i] = 1;
    }
    i++;
  }
  printf("**********************\n");
  printf("\nthe sum is: \n");
  i = 0;
  while(i!=count_input_stream){
    printf("%d\t",intput_stream[i]);
    i++;
  }

  printf("\nenter the recievers input:\n");
  scanf("%ld",&recieved_num);
  get_recievers_stream();
  i=0;
  j=count_recievers_stream-1;
  while(i!=count_input_stream && j>=0){
    if(intput_stream[i]!=recieved_stream[j]){
      iflag=1;
      break;
    }
    i++;
    j--;
  }
  if(count_input_stream!=count_recievers_stream){
    iflag=1;
  }
  if(iflag==0){
    printf("\naccepted\n");
  }
  else{
    printf("\ndiscarded\n");
  }


}
