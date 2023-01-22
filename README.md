# WinOpto: a tool for learning elementary geometric optics

**This program was developed for demonstrations of the laws of ray optics on the college physics lessons. The program allows you to create optical systems made of lenses, mirrors, and light sources, and observe the trajectories of light rays in those systems. At the time of development (2002) the program was the only one (at my knowledge) that allowed for observation of images of the objects in lenses and mirrors. The program was my graduation project at the Lyceum of Information Technologies 1533 (Лицей Информационных Технологий 1533).**

## You can download the program [here](https://github.com/dainiak/winopto/releases/tag/release)

Here goes a super-compressed reference:
- You can add optical tools (mirrors, lenses, shields, light sourses) by clicking on the corresponding toolbar buttons. When adding a object to the scene you will be presented with object properties dialog. All coordinates are based on the top-left corner of the screen.
- The object properties dialog can be shown by double-clicking on the object on the screen or double-clicking on the object name in the object list modal window.
- You can rotate mirrors, shields and light sources, and change the lenses’ focal length by clicking the object and dragging, while keeping `Ctrl` down.
- You can resize mirrors, shields and lenses by clicking the object and dragging, while keeping `Shift` down.
- You can move the objects by clicking and dragging.
- You can delete an object by double-click while pressing `Ctrl`.
- Light sources can be connected with *segments*. This enables you to demonstrate how complex images are transformed in mirrors and lenses; see the examples. To connect two light sources click the corresponding toolbar button and then click the two light sources on the scene to be selected as the endpoints of the segment.
- You will only see the image of a light source in a lens/mirror only if this light source emits the light ray that falls on that lens/mirror. You will only see the image of a segment if both of its endpoints are visualized.
- You can visualize the “ray propagation” of any given light source. To do it you will first need to choose “Select light source” from the Animation menu, then click on the desired light source on the scene. The animation start/stop/pause buttons will now be enabled on the toolbar.


The `Samples` folder contains the demonstration scenes (`.osf` extension).
Files with `.ocs` extension are the color scheme files.

The `src` folder contains the program source code (tested to compile under Microsoft Visual C++ 2022 targeting win32 platform).

![winopto](https://user-images.githubusercontent.com/2994860/158594421-74d3be70-06c4-459c-8abe-5e235ec7c7b3.png)
