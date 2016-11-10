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
 *    views: NSArray of drop views
 *    delegate: id delegate conforming to UIViewDragDropDelegave protocol
 */
- (void) enableDraggingWithDropViews:(NSArray*)dropViews delegate:(id<UIViewDragDropDelegate>)delegate;

- (void) enableDragging;

- (void) stopDragging;

- (void) setDragDropDelegate:(id<UIViewDragDropDelegate>)delegate;

- (void) changeDragMode:(UIViewDragDropMode)mode;

- (void) changeDropViews:(NSArray*)views;

- (void) changeAnimationDuration:(float)seconds;

- (void) saveStartingPosition:(BOOL)flag;

- (void) moveToStartingPosition;

@end

/**
 *  The UIViewDragDropDelegate Protocol
 */
@protocol UIViewDragDropDelegate <NSObject>

- (void) view:(UIView *)view wasDroppedOnDropView:(UIView *)drop;

@optional

- (BOOL) viewShouldReturnToStartingPosition:(UIView*)view;

- (void) viewDidReturnToStartingPosition;

- (void) draggingDidBeginForView:(UIView*)view;

- (void) draggingDidEndOutsideDropView:(UIView*)view;

- (void) view:(UIView *)view didHoverOverDropView:(UIView *)dropView;

- (void) view:(UIView *)view didUnhoverOverDropView:(UIView *)dropView;

@end
