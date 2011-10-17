#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/GuiChan/guichan/widgets/icon.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/slider.o \
	${OBJECTDIR}/GuiChan/guichan/genericinput.o \
	${OBJECTDIR}/Components/Drawable/AnimatedSpriteComponent.o \
	${OBJECTDIR}/Components/Drawable/Gui/GuiPanelComponent.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/container.o \
	${OBJECTDIR}/Exceptions/Exception.o \
	${OBJECTDIR}/Components/ScreenComponent.o \
	${OBJECTDIR}/GuiChan/sfml/sfmlimageloader.o \
	${OBJECTDIR}/ResourceManager/ResourceManager.o \
	${OBJECTDIR}/GuiChan/guichan/image.o \
	${OBJECTDIR}/InputManager/InputManager.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/radiobutton.o \
	${OBJECTDIR}/Components/EntityList/VectorEntityListComponent.o \
	${OBJECTDIR}/GuiChan/guichan/actionevent.o \
	${OBJECTDIR}/Components/EntityList/NonMapEntityListComponent.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/window.o \
	${OBJECTDIR}/GuiChan/guichan/mouseinput.o \
	${OBJECTDIR}/GuiChan/guichan/cliprectangle.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/imagebutton.o \
	${OBJECTDIR}/GuiChan/guichan/keyevent.o \
	${OBJECTDIR}/Component.o \
	${OBJECTDIR}/GuiChan/guichan/keyinput.o \
	${OBJECTDIR}/GuiChan/guichan/widget.o \
	${OBJECTDIR}/Components/Drawable/StaticSpriteComponent.o \
	${OBJECTDIR}/GuiChan/guichan/font.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/label.o \
	${OBJECTDIR}/GuiChan/guichan/selectionevent.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/listbox.o \
	${OBJECTDIR}/GuiChan/sfml/sfmlgraphics.o \
	${OBJECTDIR}/GuiChan/guichan/graphics.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/dropdown.o \
	${OBJECTDIR}/GuiChan/guichan/rectangle.o \
	${OBJECTDIR}/Components/Drawable/DrawableComponent.o \
	${OBJECTDIR}/GuiChan/guichan/basiccontainer.o \
	${OBJECTDIR}/GuiChan/guichan/imagefont.o \
	${OBJECTDIR}/Components/EntityList/EntityListComponent.o \
	${OBJECTDIR}/Squirrel/SFMLBinding.o \
	${OBJECTDIR}/GuiChan/sfml/sfmlfont.o \
	${OBJECTDIR}/GuiChan/guichan/mouseevent.o \
	${OBJECTDIR}/GuiChan/sfml/sfmlinput.o \
	${OBJECTDIR}/Squirrel/Bindings.o \
	${OBJECTDIR}/GuiChan/sfml/sfmlimage.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/tab.o \
	${OBJECTDIR}/GuiChan/guichan/key.o \
	${OBJECTDIR}/GuiChan/guichan/defaultfont.o \
	${OBJECTDIR}/GuiChan/guichan/guichan.o \
	${OBJECTDIR}/GuiChan/guichan/focushandler.o \
	${OBJECTDIR}/Components/Drawable/SpriteComponent.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/textbox.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/textfield.o \
	${OBJECTDIR}/GuiChan/guichan/event.o \
	${OBJECTDIR}/Factory/ComponentFactory.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/scrollarea.o \
	${OBJECTDIR}/Tracer/Tracer.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/checkbox.o \
	${OBJECTDIR}/Entity.o \
	${OBJECTDIR}/GuiChan/guichan/exception.o \
	${OBJECTDIR}/GuiChan/guichan/gui.o \
	${OBJECTDIR}/GuiChan/guichan/color.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/button.o \
	${OBJECTDIR}/GuiChan/guichan/inputevent.o \
	${OBJECTDIR}/Game/Game.o \
	${OBJECTDIR}/GuiChan/guichan/widgets/tabbedarea.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libdokuro2.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libdokuro2.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libdokuro2.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libdokuro2.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libdokuro2.a

${OBJECTDIR}/GuiChan/guichan/widgets/icon.o: GuiChan/guichan/widgets/icon.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/icon.o GuiChan/guichan/widgets/icon.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/slider.o: GuiChan/guichan/widgets/slider.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/slider.o GuiChan/guichan/widgets/slider.cpp

${OBJECTDIR}/GuiChan/guichan/genericinput.o: GuiChan/guichan/genericinput.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/genericinput.o GuiChan/guichan/genericinput.cpp

${OBJECTDIR}/Components/Drawable/AnimatedSpriteComponent.o: Components/Drawable/AnimatedSpriteComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/Components/Drawable
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Components/Drawable/AnimatedSpriteComponent.o Components/Drawable/AnimatedSpriteComponent.cpp

${OBJECTDIR}/Components/Drawable/Gui/GuiPanelComponent.o: Components/Drawable/Gui/GuiPanelComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/Components/Drawable/Gui
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Components/Drawable/Gui/GuiPanelComponent.o Components/Drawable/Gui/GuiPanelComponent.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/container.o: GuiChan/guichan/widgets/container.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/container.o GuiChan/guichan/widgets/container.cpp

${OBJECTDIR}/Exceptions/Exception.o: Exceptions/Exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/Exceptions
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Exceptions/Exception.o Exceptions/Exception.cpp

${OBJECTDIR}/Components/ScreenComponent.o: Components/ScreenComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/Components
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Components/ScreenComponent.o Components/ScreenComponent.cpp

${OBJECTDIR}/GuiChan/sfml/sfmlimageloader.o: GuiChan/sfml/sfmlimageloader.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/sfml
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/sfml/sfmlimageloader.o GuiChan/sfml/sfmlimageloader.cpp

${OBJECTDIR}/ResourceManager/ResourceManager.o: ResourceManager/ResourceManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/ResourceManager
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ResourceManager/ResourceManager.o ResourceManager/ResourceManager.cpp

${OBJECTDIR}/GuiChan/guichan/image.o: GuiChan/guichan/image.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/image.o GuiChan/guichan/image.cpp

${OBJECTDIR}/InputManager/InputManager.o: InputManager/InputManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/InputManager
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/InputManager/InputManager.o InputManager/InputManager.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/radiobutton.o: GuiChan/guichan/widgets/radiobutton.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/radiobutton.o GuiChan/guichan/widgets/radiobutton.cpp

${OBJECTDIR}/Components/EntityList/VectorEntityListComponent.o: Components/EntityList/VectorEntityListComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/Components/EntityList
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Components/EntityList/VectorEntityListComponent.o Components/EntityList/VectorEntityListComponent.cpp

${OBJECTDIR}/GuiChan/guichan/actionevent.o: GuiChan/guichan/actionevent.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/actionevent.o GuiChan/guichan/actionevent.cpp

${OBJECTDIR}/Components/EntityList/NonMapEntityListComponent.o: Components/EntityList/NonMapEntityListComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/Components/EntityList
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Components/EntityList/NonMapEntityListComponent.o Components/EntityList/NonMapEntityListComponent.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/window.o: GuiChan/guichan/widgets/window.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/window.o GuiChan/guichan/widgets/window.cpp

${OBJECTDIR}/GuiChan/guichan/mouseinput.o: GuiChan/guichan/mouseinput.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/mouseinput.o GuiChan/guichan/mouseinput.cpp

${OBJECTDIR}/GuiChan/guichan/cliprectangle.o: GuiChan/guichan/cliprectangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/cliprectangle.o GuiChan/guichan/cliprectangle.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/imagebutton.o: GuiChan/guichan/widgets/imagebutton.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/imagebutton.o GuiChan/guichan/widgets/imagebutton.cpp

${OBJECTDIR}/GuiChan/guichan/keyevent.o: GuiChan/guichan/keyevent.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/keyevent.o GuiChan/guichan/keyevent.cpp

${OBJECTDIR}/Component.o: Component.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Component.o Component.cpp

${OBJECTDIR}/GuiChan/guichan/keyinput.o: GuiChan/guichan/keyinput.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/keyinput.o GuiChan/guichan/keyinput.cpp

${OBJECTDIR}/GuiChan/guichan/widget.o: GuiChan/guichan/widget.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widget.o GuiChan/guichan/widget.cpp

${OBJECTDIR}/Components/Drawable/StaticSpriteComponent.o: Components/Drawable/StaticSpriteComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/Components/Drawable
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Components/Drawable/StaticSpriteComponent.o Components/Drawable/StaticSpriteComponent.cpp

${OBJECTDIR}/GuiChan/guichan/font.o: GuiChan/guichan/font.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/font.o GuiChan/guichan/font.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/label.o: GuiChan/guichan/widgets/label.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/label.o GuiChan/guichan/widgets/label.cpp

${OBJECTDIR}/GuiChan/guichan/selectionevent.o: GuiChan/guichan/selectionevent.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/selectionevent.o GuiChan/guichan/selectionevent.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/listbox.o: GuiChan/guichan/widgets/listbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/listbox.o GuiChan/guichan/widgets/listbox.cpp

${OBJECTDIR}/GuiChan/sfml/sfmlgraphics.o: GuiChan/sfml/sfmlgraphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/sfml
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/sfml/sfmlgraphics.o GuiChan/sfml/sfmlgraphics.cpp

${OBJECTDIR}/GuiChan/guichan/graphics.o: GuiChan/guichan/graphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/graphics.o GuiChan/guichan/graphics.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/dropdown.o: GuiChan/guichan/widgets/dropdown.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/dropdown.o GuiChan/guichan/widgets/dropdown.cpp

${OBJECTDIR}/GuiChan/guichan/rectangle.o: GuiChan/guichan/rectangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/rectangle.o GuiChan/guichan/rectangle.cpp

${OBJECTDIR}/Components/Drawable/DrawableComponent.o: Components/Drawable/DrawableComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/Components/Drawable
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Components/Drawable/DrawableComponent.o Components/Drawable/DrawableComponent.cpp

${OBJECTDIR}/GuiChan/guichan/basiccontainer.o: GuiChan/guichan/basiccontainer.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/basiccontainer.o GuiChan/guichan/basiccontainer.cpp

${OBJECTDIR}/GuiChan/guichan/imagefont.o: GuiChan/guichan/imagefont.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/imagefont.o GuiChan/guichan/imagefont.cpp

${OBJECTDIR}/Components/EntityList/EntityListComponent.o: Components/EntityList/EntityListComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/Components/EntityList
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Components/EntityList/EntityListComponent.o Components/EntityList/EntityListComponent.cpp

${OBJECTDIR}/Squirrel/SFMLBinding.o: Squirrel/SFMLBinding.cpp 
	${MKDIR} -p ${OBJECTDIR}/Squirrel
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Squirrel/SFMLBinding.o Squirrel/SFMLBinding.cpp

${OBJECTDIR}/GuiChan/sfml/sfmlfont.o: GuiChan/sfml/sfmlfont.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/sfml
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/sfml/sfmlfont.o GuiChan/sfml/sfmlfont.cpp

${OBJECTDIR}/GuiChan/guichan/mouseevent.o: GuiChan/guichan/mouseevent.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/mouseevent.o GuiChan/guichan/mouseevent.cpp

${OBJECTDIR}/GuiChan/sfml/sfmlinput.o: GuiChan/sfml/sfmlinput.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/sfml
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/sfml/sfmlinput.o GuiChan/sfml/sfmlinput.cpp

${OBJECTDIR}/Squirrel/Bindings.o: Squirrel/Bindings.cpp 
	${MKDIR} -p ${OBJECTDIR}/Squirrel
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Squirrel/Bindings.o Squirrel/Bindings.cpp

${OBJECTDIR}/GuiChan/sfml/sfmlimage.o: GuiChan/sfml/sfmlimage.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/sfml
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/sfml/sfmlimage.o GuiChan/sfml/sfmlimage.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/tab.o: GuiChan/guichan/widgets/tab.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/tab.o GuiChan/guichan/widgets/tab.cpp

${OBJECTDIR}/GuiChan/guichan/key.o: GuiChan/guichan/key.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/key.o GuiChan/guichan/key.cpp

${OBJECTDIR}/GuiChan/guichan/defaultfont.o: GuiChan/guichan/defaultfont.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/defaultfont.o GuiChan/guichan/defaultfont.cpp

${OBJECTDIR}/GuiChan/guichan/guichan.o: GuiChan/guichan/guichan.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/guichan.o GuiChan/guichan/guichan.cpp

${OBJECTDIR}/GuiChan/guichan/focushandler.o: GuiChan/guichan/focushandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/focushandler.o GuiChan/guichan/focushandler.cpp

${OBJECTDIR}/Components/Drawable/SpriteComponent.o: Components/Drawable/SpriteComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/Components/Drawable
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Components/Drawable/SpriteComponent.o Components/Drawable/SpriteComponent.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/textbox.o: GuiChan/guichan/widgets/textbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/textbox.o GuiChan/guichan/widgets/textbox.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/textfield.o: GuiChan/guichan/widgets/textfield.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/textfield.o GuiChan/guichan/widgets/textfield.cpp

${OBJECTDIR}/GuiChan/guichan/event.o: GuiChan/guichan/event.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/event.o GuiChan/guichan/event.cpp

${OBJECTDIR}/Factory/ComponentFactory.o: Factory/ComponentFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/Factory
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Factory/ComponentFactory.o Factory/ComponentFactory.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/scrollarea.o: GuiChan/guichan/widgets/scrollarea.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/scrollarea.o GuiChan/guichan/widgets/scrollarea.cpp

${OBJECTDIR}/Tracer/Tracer.o: Tracer/Tracer.cpp 
	${MKDIR} -p ${OBJECTDIR}/Tracer
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Tracer/Tracer.o Tracer/Tracer.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/checkbox.o: GuiChan/guichan/widgets/checkbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/checkbox.o GuiChan/guichan/widgets/checkbox.cpp

${OBJECTDIR}/Entity.o: Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Entity.o Entity.cpp

${OBJECTDIR}/GuiChan/guichan/exception.o: GuiChan/guichan/exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/exception.o GuiChan/guichan/exception.cpp

${OBJECTDIR}/GuiChan/guichan/gui.o: GuiChan/guichan/gui.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/gui.o GuiChan/guichan/gui.cpp

${OBJECTDIR}/GuiChan/guichan/color.o: GuiChan/guichan/color.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/color.o GuiChan/guichan/color.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/button.o: GuiChan/guichan/widgets/button.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/button.o GuiChan/guichan/widgets/button.cpp

${OBJECTDIR}/GuiChan/guichan/inputevent.o: GuiChan/guichan/inputevent.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/inputevent.o GuiChan/guichan/inputevent.cpp

${OBJECTDIR}/Game/Game.o: Game/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/Game
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Game/Game.o Game/Game.cpp

${OBJECTDIR}/GuiChan/guichan/widgets/tabbedarea.o: GuiChan/guichan/widgets/tabbedarea.cpp 
	${MKDIR} -p ${OBJECTDIR}/GuiChan/guichan/widgets
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GuiChan/guichan/widgets/tabbedarea.o GuiChan/guichan/widgets/tabbedarea.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libdokuro2.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
