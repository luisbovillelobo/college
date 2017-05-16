#include <stdio.h>
#include <math.h>

/****************************************************/

struct Rect {
         double coX, coY;
       };

struct Polar {
         double rad, ang;
       };

void * polar2rect (const struct Polar *);
struct Rect PolarRect (const struct Polar *);

/****************************************************/

void * polar2rect (const struct Polar * punto)
{
   static struct Rect rt;   /* debe ser static */

   rt.coX = punto->rad * cos(punto->ang);
   rt.coY = punto->rad * sin(punto->ang);
   return (void *) &rt;
}

/****************************************************/

struct Rect PolarRect (const struct Polar * punto)
{
   struct Rect rct;

   rct.coX = punto->rad * cos(punto->ang);
   rct.coY = punto->rad * sin(punto->ang);
   return rct;
}

/****************************************************/

void main()
{
   struct Polar P = {1,0} ;
   struct Rect * R, S;

   R = polar2rect(&P);
   printf("%lf  %lf\n",R->coX,R->coY);
   P.rad = 5;
   P.ang = 10;
   R = polar2rect(&P);
   printf("%lf  %lf\n",R->coX,R->coY);
   S = PolarRect(&P);
   printf("%lf  %lf\n",S.coX,S.coY);
}
