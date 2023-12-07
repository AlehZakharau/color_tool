#include <stdio.h>
#include <math.h>

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

void check_small_range(double *c){
   if(*c < 0.0)
      *c = 0.0;
   else if(*c > 1.0)
      *c = 1.0;
}

void check_input_color(color *col){
   check_range(&col->r);
   check_range(&col->g);
   check_range(&col->b);
}

void chaeck_input_small_color(color *col){
   check_small_range(&col->r);
   check_small_range(&col->g);
   check_small_range(&col->b);
}

color convert_color(color *col){
   color col_out = { col->r / 255.0, col->g / 255.0, col->b / 255.0 };
   return col_out;
}

color conver_color_to_big(color *col){
   color col_out = { col->r * 255.0, col->g * 255.0, col->b * 255.0 };
   return col_out;
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

   color col_out = convert_color(col);
   printf("Output ");
   print_color(&col_out);
   printf("\n:::\n\n");
}

void input_small_range_color(color *col){
   printf("Print red color in 0-1 range: ");
   scanf("%lf", &col->r);
   printf("Print green color in 0-1 range: ");
   scanf("%lf", &col->g);
   printf("Print blue color in 0-1 range: ");
   scanf("%lf", &col->b);
   chaeck_input_small_color(col);

   printf("\nInput ");
   print_color(col);

   color col_out = conver_color_to_big(col);
   printf("Output ");
   print_color(&col_out);
   printf("\n:::\n\n");
}


int input_command(color *col){
   int command;
   printf("Choose command \n\"BIG\" == 1 or \"SMALL\" == 2 ");
   scanf("%d", &command);

   if(command == 1){
      input_big_range_color(col);
   }
   else if(command == 2){
      input_small_range_color(col);
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