#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *f = fopen("image.ppm", "w");
  fprintf(f, "P3\n500 500\n255\n");

  int r = 0;
  int g = 0;
  int b = 0;

  int r2 = 255;
  int g2 = 255;
  int b2 = 255;
  
  int count = 0;
  
  for (count; count < 250000; count++){
    if (count % 250 == 0 || count / 500 == 250){
      fprintf(f, "%d %d %d\n", r, g, b);
      if (r < 255)
	r += 1;
      else if (g < 255)
	g += 1;
      else if (b < 255)
	b += 1;
      else {
	r = 0;
	g = 0;
	b = 0;
      }
    }
    else{
      fprintf(f, "%d %d %d\n", r2, g2, b2);
      int random = rand() % 4; 
      if (random == 1)
	r2 = r2 - 1;
      if (random == 2)
	g2 = r2 - 1;
      if (random == 3)
	b2 = r2 - 1;
      if (r2 == 0 | g2 == 0 | b2 == 0){
	r2 = 255;
	g2 = 255;
	b2 = 255;
      }
    }
  }
  fclose(f);
  
  return 0;
}
