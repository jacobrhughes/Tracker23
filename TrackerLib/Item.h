/**
 * @file Item.h
 * @author Jacob Hughes
 *
 *
 */

#ifndef TESTTRACKER22_ITEM_H
#define TESTTRACKER22_ITEM_H

#include <wx/xml/xml.h>
class Tracker;

/**
 * Class that describes an item, vector of items held in Day class
 */
class Item {
private:

    /// The Tracker the item is contained in
    Tracker *mTracker;

    // Item locations in the Tracker
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

protected:
    Item(Tracker *tracker);

public:

    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    /// Assignment operator
    void operator=(const Item &) = delete;

    /**
     * The X location of the item
     * @return X location in pixels
     */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    void SetLocation(double x, double y) { mX = x; mY = y; }

    /**
     * Draw the item
     * @param graphics the graphics to draw on
     * @param x the x location of the item
     * @param y the y location of the item
     * @param option option to use when drawing
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, std::wstring option) {};

    /**
     * Get the tracker
     * @return the pointer to the tracker
     */
    Tracker *GetTracker() {return mTracker;}

    /**
     * get the event day, overridden in derived class to make possible
     * @return the event day
     */
    virtual int GetEventDay() =0;

    /**
      * get the event month, overridden in derived class to make possible
      * @return the event month
      */
    virtual int GetEventMonth() =0;

    /**
      * get the event year, overridden in derived class to make possible
      * @return the event year
      */
    virtual int GetEventYear() =0;

    /**
     * Set the image name, overridden in derived class to make possible
     * @param imageName the image name to set
     */
    virtual void SetImageName(std::wstring imageName) =0;

    /**
     * Set the image name, overridden in derived class to make possible
     * @return the image name
     */
    virtual std::wstring GetImageName() =0;

    /**
     * Get the color, overridden in derived class to make possible
     * @return the color
     */
    virtual wxColour GetColor() =0;

    /**
     * Get the event type, overridden in derived class to make possible
     * @return the event type
     */
    virtual std::wstring GetEventType() =0;

    /**
     * Get the event description, overridden in derived class to make possible
     * @return the event type
     */
    virtual std::wstring GetEventDescription() =0;

    virtual wxXmlNode *XmlSave(wxXmlNode *node);

};

#endif //TESTTRACKER22_ITEM_H
