#include    <osg/Switch>
#include    <osgDB/ReadFile>
#include    <osgViewer/Viewer>

//------------------------------------------------------------------------------


//
//------------------------------------------------------------------------------
class SwitchingCallback : public osg::NodeCallback
{
public:

    SwitchingCallback() : _count(0) {}

    virtual void operator()(osg::Node *node, osg::NodeVisitor *nv);

protected:

    unsigned int _count;
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void SwitchingCallback::operator()(osg::Node *node, osg::NodeVisitor *nv)
{
    osg::Switch *switchNode = static_cast<osg::Switch *>(node);

    if ( !((++_count) % 60) && switchNode )
    {
        switchNode->setValue(0, !switchNode->getValue(0));
        switchNode->setValue(1, !switchNode->getValue(0));
    }

    traverse(node, nv);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    (void) argc; (void) argv;

    osg::ref_ptr<osg::Node> model1 = osgDB::readNodeFile("../resourses/cessna.osg");
    osg::ref_ptr<osg::Node> model2 = osgDB::readNodeFile("../resourses/cessnafire.osg");

    osg::ref_ptr<osg::Switch> root = new osg::Switch;
    root->addChild(model1, true);
    root->addChild(model2, false);

    root->setUpdateCallback( new SwitchingCallback );

    osgViewer::Viewer viewer;
    viewer.setSceneData(root.get());

    return viewer.run();
}
