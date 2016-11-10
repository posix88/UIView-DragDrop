//
//  UIView+DragDrop.h
//
//  Created by Ryan Meisters.
//

#import <UIKit/UIKit.h>


typedef NS_ENUM( NSInteger, UIViewDragDropMode) {
    UIViewDragDropModeNormal,
    UIViewDragDropModeRestrictY,
    UIViewDragDropModeRestrictX
};

@protocol UIViewDragDropDelegate;

/**
 *  A Category that adds Drag and drop functionality to UIView
 */
@interface UIView (DragDrop)

/**
 *  Set up drag+drop
 *  @params
 *    dropViews: NSArray of drop views
 *    delegate: id delegate conforming to UIViewDragDropDelegave protocol
 */
- (void) enableDraggingWithDropViews:(NSArray*)dropViews delegate:(id<UIViewDragDropDelegate>)delegate;

/// Set up drag+drop without drop views and delegate
- (void) enableDragging;

/// Stop dragging on the current view
- (void) stopDragging;

/// Set up the delegate for the UIViewDragDropDelegate Protocol
- (void) setDragDropDelegate:(id<UIViewDragDropDelegate>)delegate;

/// Set up o change the Drag mode
- (void) changeDragMode:(UIViewDragDropMode)mode;

/// Set up o change the Drop Views
- (void) changeDropViews:(NSArray*)views;

/// Set up o change the returning to the initial position animation duration
- (void) changeAnimationDuration:(float)seconds;

/// Save the initial position of the view
- (void) saveStartingPosition:(BOOL)flag;

/// Start the returning to the initial position animation
- (void) moveToStartingPosition;

@end

/**
 *  The UIViewDragDropDelegate Protocol
 */
@protocol UIViewDragDropDelegate <NSObject>

/**
 * This method informs you that your view was dropped on one of your drop views
 * @params
 *      view: your draggable view
 *      drop: the drop view on which your draggable view was dropped
 */
- (void) view:(UIView *)view wasDroppedOnDropView:(UIView *)drop;

@optional

/**
 * This method informs you that your view is about to return to its initial position
 * @params
 *      view: your draggable view
 */
- (BOOL) viewShouldReturnToStartingPosition:(UIView*)view;

/// This method informs you that your view returned to its initial position
- (void) viewDidReturnToStartingPosition;

/// This method informs you that your view returned to its initial position
- (void) draggingDidBeginForView:(UIView*)view;

- (void) draggingDidEndOutsideDropView:(UIView*)view;

- (void) view:(UIView *)view didHoverOverDropView:(UIView *)dropView;

- (void) view:(UIView *)view didUnhoverOverDropView:(UIView *)dropView;

@end
