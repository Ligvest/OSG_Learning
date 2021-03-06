#pragma once

#include <osgGA/GUIEventHandler>
#include <osgGA/StandardManipulator>
#include <osgViewer/Viewer>

class FreeCameraManipulator : public osgGA::StandardManipulator
{
public:
    FreeCameraManipulator();
	FreeCameraManipulator(const FreeCameraManipulator& om, const osg::CopyOp& copyOp = osg::CopyOp::SHALLOW_COPY);

    virtual osg::Matrixd getMatrix() const;
    virtual osg::Matrixd getInverseMatrix() const;
    virtual void setByMatrix(const osg::Matrixd& matrix);
    virtual void setByInverseMatrix(const osg::Matrixd& matrix);
    
    virtual void setTransformation(const osg::Vec3d& eye, const osg::Quat& rotation);
    virtual void setTransformation(const osg::Vec3d& eye, const osg::Vec3d& center, const osg::Vec3d& up);
    virtual void getTransformation(osg::Vec3d& eye, osg::Quat& rotation) const;
    virtual void getTransformation(osg::Vec3d& eye, osg::Vec3d& center, osg::Vec3d& up) const;

    virtual void home(double h);
    virtual void home(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);

	/*
		Sets camera position.
	*/
    void setPosition(const osg::Vec3& position);
	
	/*
		Sets speed of camera move.
	*/
	void setSpeed(double speed);
	
	/*
        Sets mouse sensitivity. By default, 1.0.
	*/
	void setMouseSensitivity(double sens);

    virtual bool handleMouseMove(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us) override;
    virtual bool handleKeyDown(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us) override;
    virtual bool handleKeyUp(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us) override;
    virtual bool handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &aa) override;


protected:
    osg::Vec3d _position;
	osg::Quat _rotation;

	double _x;
	double _y;

	osg::Vec3d _move;

    //mouse sensitivity and move speed
	double _sensitivity;
	double _speed;

    //If buttons are pressed
    bool _isWPressed;
    bool _isAPressed;
    bool _isSPressed;
    bool _isDPressed;

};
