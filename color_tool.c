#include <stdio.h>
#include <math.h>

#define BIG = 1
#define SMALL = 2
#define END = 0

typedef struct color{
   double r;
   double g;
   double b;
} color;

void print_color(color *col){
   printf("Color: < %.2lf | %.2lf | %.2lf >\n", col->r, col->g, col->b);
}

void check_range(double *c){
   if(*c < 0.0)
      *c = 0.0;
   else if(*c > 255.0)
      *c = 255.0;
}

void check_input_color(color *col){
   check_range(&col->r);
   check_range(&col->g);
   check_range(&col->b);
}

color convert_color(color *col){
   color col_out = { col->r / 255.0, col->g / 255.0, col->b / 255.0 };
   return col_out;
}

void print_output(color *col){
   color col_out = convert_color(col);
   printf("Output ");
   print_color(&col_out);
   printf("\n:::\n\n");

   //input_comman(col);
}

void input_big_range_color(color *col){
   printf("Print red color in 0-255 range: ");
   scanf("%lf", &col->r);
   printf("Print green color in 0-255 range: ");
   scanf("%lf", &col->g);
   printf("Print blue color in 0-255 range: ");
   scanf("%lf", &col->b);
   check_input_color(col);

   printf("\nInput ");
   print_color(col);

   print_output(col);
}


int input_command(color *col){
   int command;
   printf("Choose command \n\"BIG\" == 1 or \"SMALL\" == 2 ");
   scanf("%d", &command);

   if(command == 1){
      input_big_range_color(col);
   }
   return command;
}



int main(){
   color col = {0.0, 0.0, 0.0};
   int command = input_command(&col);

   if(command != 0)
      input_command(&col);

   return 0;
}