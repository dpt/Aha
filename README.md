Aha!
====

This is Henry S. Warren's '[Aha!](http://hackersdelight.org/)' superoptimiser tool with a couple of mods make it more appropriate for targeting ARM and Thumb code. e.g. It knows about the `BIC` and `RSB` instructions.

It also has various rejiggery of source the exact nature of which escapes me at the moment. The original source is available on the 'distrib' branch.

Build a binary with:

    make EXAMPLE=<fragment>

Where `<fragment>` is one of the xxx.frag.c files in the source directory.

Then run the resultant 'aha' with the number of target instructions.

    ./aha 2

Enjoy!


Presentation
------------

In September 2016 I gave [a presentation about superoptimisers](http://slides.com/dpt/aha#/) to my then colleagues at [Inside Secure](https://www.insidesecure.com/).
