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

void check_input_color(color *col){
   check_range(&col->r);
   check_range(&col->g);
   check_range(&col->b);
}

color convert_color(color *col){
   color col_out = { col->r / 255.0, col->g / 255.0, col->b / 255.0 };
   return col_out;
}

int main(){
   color col = {0.0, 0.0, 0.0};
   printf("Enter red color in 0-255 range: ");
   scanf("%lf", &col.r);
   printf("Enter green color in 0-255 range: ");
   scanf("%lf", &col.g);
   printf("Enter blue color in 0-255 range: ");
   scanf("%lf", &col.b);
   check_input_color(&col);

   printf("Input ");
   print_color(&col);

   color col_out = convert_color(&col);
   printf("Output ");
   print_color(&col_out);

   return 0;
}