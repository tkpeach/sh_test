#include <stdlib.h>                 // Required for: malloc(), free()

#define MAX_BUNNIES        100000   // 100K bunnies limit

// This is the maximum amount of elements (quads) per batch
// NOTE: This value is defined in [rlgl] module and can be changed there
#define MAX_BATCH_ELEMENTS  8192

// static char *(*get_resource_path)(const char *path) = _get_resource_path;

typedef struct Bunny {
	float x;
	float y;
	float sx;
	float sy;
} Bunny;

  void createBunnies(int requested, int* bunniesCount, Bunny* bunny)
  // void createBunnies(int requested, int* bunniesCount, Bunny* bunnies)
  {
    int count = (*bunniesCount + requested <= MAX_BUNNIES) ? requested : MAX_BUNNIES - *bunniesCount; 
    for (int i = 0; i < count; i++)
    {
        if (*bunniesCount <= MAX_BUNNIES)
        {
            bunny->x = 50.0/2;
            bunny->y = 88.0/2;
            bunny->sx = 50.0/60.0f;
            bunny->sy = 250.0/60.0f;

            (*bunniesCount)++;
        }
    }
  }

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 640;
    const int screenHeight = 480;

    Bunny bunny;

    int bunniesCount = 0;           // Bunnies counter

    //--------------------------------------------------------------------------------------

    // Main game loop
    {
        // Update
        //----------------------------------------------------------------------------------

        // Update Input
        {
            createBunnies(MAX_BUNNIES, &bunniesCount, &bunny);
            // createBunnies(MAX_BUNNIES, &bunniesCount, bunnies);
        }

        // Update bunnies
        for (int j = 0; j < 10000; j++) {
        for (int i = 0; i < bunniesCount; i++)
        {
            bunny.x += bunny.sx;
            bunny.y += bunny.sy;

            if (((bunny.x + 20/2) > 640) ||
                ((bunny.x + 20/2) < 0)) bunny.sx *= -1;
            if (((bunny.y + 20/2) > 480) ||
                ((bunny.y + 20/2 - 40) < 0)) bunny.sy *= -1;

            // bunny_x[i] += bunny_sx[i];
            // bunny_y[i] += bunny_sy[i];

            // if (((bunny_x[i] + 20/2) > 20) ||
                // ((bunny_x[i] + 20/2) < 0)) bunny_sx[i] *= -1;
            // if (((bunny_y[i] + 20/2) > 40) ||
                // ((bunny_y[i] + 20/2 - 40) < 0)) bunny_sy[i] *= -1;

            // bunnies[i].position.x += bunnies[i].speed.x;
            // bunnies[i].position.y += bunnies[i].speed.y;

            // if (((bunnies[i].position.x + 20/2) > GetScreenWidth()) ||
                // ((bunnies[i].position.x + 20/2) < 0)) bunnies[i].speed.x *= -1;
            // if (((bunnies[i].position.y + 20/2) > GetScreenHeight()) ||
                // ((bunnies[i].position.y + 20/2 - 40) < 0)) bunnies[i].speed.y *= -1;
        }
	}
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    // free(bunny_x);              // Unload bunnies data array
    // free(bunny_y);              // Unload bunnies data array
    // free(bunny_sx);              // Unload bunnies data array
    // free(bunny_sy);              // Unload bunnies data array
    // free(bunnies);              // Unload bunnies data array

    //--------------------------------------------------------------------------------------

    return 0;
}
