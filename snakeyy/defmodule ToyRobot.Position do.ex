defmodule ToyRobot.Position do
  defstruct x: 0, y: 0, facing: :north

  def place do
    %ToyRobot.Position{}
  end

  def place(x, y, facing) do
    %ToyRobot.Position{x: x, y: y, facing: facing}
  end

end
