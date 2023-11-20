from graphics import *

# Create a graphics window
win = GraphWin("Linux Penguin", 300, 300)

# Function to draw a filled circle
def draw_circle(center, radius, color):
    circle = Circle(center, radius)
    circle.setFill(color)
    circle.draw(win)

# Function to draw the Linux penguin
def draw_penguin():
    # Draw the body
    body_center = Point(150, 200)
    draw_circle(body_center, 100, "black")

    # Draw the head
    head_center = Point(150, 100)
    draw_circle(head_center, 50, "black")

    # Draw the eyes
    eye1_center = Point(130, 120)
    draw_circle(eye1_center, 10, "white")
    eye2_center = Point(170, 120)
    draw_circle(eye2_center, 10, "white")

    # Draw the beak
    beak = Polygon(Point(150, 130), Point(140, 110), Point(160, 110))
    beak.setFill("orange")
    beak.draw(win)

    # Draw the feet
    foot1_center = Point(130, 250)
    draw_circle(foot1_center, 10, "orange")
    foot2_center = Point(170, 250)
    draw_circle(foot2_center, 10, "orange")

# Draw the Linux penguin
draw_penguin()

# Wait for mouse click to close the window
win.getMouse()
win.close()
