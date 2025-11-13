class Point:
    def __init__(self, xcor=0, ycor=0):
        # this would make the varable private:
            # self.__x_cor = xcor
            # self.__y_cor = ycor
        self.x_cor = xcor
        self.y_cor = ycor
    
    def __str__(self):
        return f"( {self.x_cor}, {self.y_cor} )"

    def __len__(self):
        return 2
    
    def __eq__(self, other):
        return self.x_cor == other.x_cor and self.y_cor == other.y_cor

    def translation(self, delta_x, delta_y):
        self.x_cor += delta_x
        self.y_cor += delta_y
    
    def distance(self, other):
        delta_x = self.x_cor - other.x_cor
        delta_y = self.y_cor - other.y_cor
        squares_sum = delta_x ** 2 + delta_y ** 2
        dist = squares_sum ** 0.5
        return dist