with Ada.Float_Text_IO;
with Ada.Text_IO;
procedure Lab_2_1_Book is

   type trucking_company is record
      oil_change: Integer :=0;
      washing_fluid: Float:=0.0;
      air_filter: Integer:=0;
      fuel: Float:=0.0;
      comp_pizza_luncheon: Float:=0.0;
      end record;
   your_trucking_comp: trucking_company;
begin
   your_trucking_comp.oil_change := 440;
   your_trucking_comp.washing_fluid := 98.40;
   your_trucking_comp.air_filter := 23;
   your_trucking_comp.fuel := 900.40;
   your_trucking_comp.comp_pizza_luncheon:=71.49;

   --  Insert code here.
   Ada.Text_IO.Put_Line("Oil Change := " & Integer'Image(your_trucking_comp.oil_change));

   Ada.Text_IO.Put("Washing Fluid:= ");
   Ada.Float_Text_IO.Put(your_trucking_comp.washing_fluid,aft=>2,exp=>0);
   Ada.Text_IO.New_Line;

   Ada.Text_IO.Put_Line("Air Filter := " & Integer'Image(your_trucking_comp.air_filter));

   Ada.Text_IO.Put("Fuel := ");
   Ada.Float_Text_IO.Put(your_trucking_comp.fuel,aft=>1,exp=>0);
   Ada.Text_IO.New_Line;

   Ada.Text_IO.Put("Company Pizza Luncheon := ");
   Ada.Float_Text_IO.Put(your_trucking_comp.comp_pizza_luncheon,aft=>2,exp=>0);


end Lab_2_1_Book;
