
  /// Pack color channels into a 32-bit unsigned integer.
  function makeColor(r, g, b, a){
    "inline";
    return (a << 24) | (b << 16) | (g << 8) | r;
  }

  // Constants
  const MAX_BUNNIES = 100000;
  const MAX_BATCH_ELEMENTS = 8192;

  // class Bunny {
    // pos_x: number;
    // pos_y: number;
    // speed_x: number;
    // speed_y: number;
    // color: number;

    // constructor(pos_x: number, pos_y: number, speed_x: number, speed_y: number, color: number) {
        // this.pos_x = pos_x;
        // this.pos_y = pos_y;
        // this.speed_x = speed_x;
        // this.speed_y = speed_y;
        // this.color = color;
    // }
  // }
  
  // Bunnies data
  // TODO: new Array(MAX_BUNNIES) causes a runtime assertion when assigning the elements of the array
  // const bunnies: Bunny[] = [];
  // const bunnies: Bunny[] = [];
  let bunny_x = 0;
  let bunny_y = 0;
  let bunny_sx = 0;
  let bunny_sy = 0;
  // const bunnies: Bunny[] = [];
  let bunniesCount = 0;

  // Initialization
  const width = 640, height = 480;
  const wabbitDim_w = 20;
  const wabbitDim_h = 20;

  // Create more bunnies on spacebar or mouse click
  const createBunnies = (requested) => {
    // const count:number = MAX_BUNNIES;
    const count:number = (bunniesCount + requested <= MAX_BUNNIES) ? requested : MAX_BUNNIES - bunniesCount; 
    for (let i = 0; i < count; i++)
    {
      if (bunniesCount <= MAX_BUNNIES)
      {
	bunny_x = width/2;
	bunny_y = width/2;
	bunny_sx = 50/60;
	bunny_sy = 250/60;
        // bunnies.push(new Bunny(
          // width/2,
          // height/2,
          // 250/60,
          // 250/60,
          // makeColor(40, 80,100, 55)));
        bunniesCount++;
      }
    }
  }

  // Main game loop
  createBunnies(MAX_BUNNIES);

  // Update bunnies speed and position
  for (let i = 0; i < 10000; i++) {
   for (let i = 0; i < bunniesCount; i++)
    {
      bunny_x += bunny_sx;
      bunny_y += bunny_sy;

      if (((bunny_x + wabbitDim_w/2) > width) || ((bunny_x + wabbitDim_w/2) < 0)) bunny_sx *= -1;
      if (((bunny_y + wabbitDim_h/2) > height) || ((bunny_y + wabbitDim_h/2 - 40) < 0)) bunny_sy *= -1;
      
      // let bunny: Bunny = bunnies[i];
      // bunny.pos_x += bunny.speed_x;
      // bunny.pos_y += bunny.speed_y;

      // if (((bunny.pos_x + wabbitDim_w/2) > width) || ((bunny.pos_x + wabbitDim_w/2) < 0)) bunny.speed_x *= -1;
      // if (((bunny.pos_y + wabbitDim_h/2) > height) || ((bunny.pos_y + wabbitDim_h/2 - 40) < 0)) bunny.speed_y *= -1;
    }
  }

