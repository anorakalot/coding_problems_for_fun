-- animal.adb:
package body Animal is
   function Init -- parameter constructor
     (Name       : in String; Legs : in Natural; WeightInGrams : in Positive;
      HeightInCm : in Positive) return Creature
   is
      TempCreature : Creature;
   begin
      if (legs > 1000) then
         raise too_many_legs_exception;
      end if;

      if (HeightInCm > 2000) then
         raise height_too_large;
         end if;
      TempCreature.Name := Ada.Strings.Unbounded.To_Unbounded_String (Name);

      TempCreature.Legs          := Legs;
      TempCreature.WeightInGrams := WeightInGrams;

      TempCreature.HeightInCm    := HeightInCm;
      return TempCreature;
   exception
      when too_many_legs_exception =>
         Ada.Text_IO.Put_Line("too many legs exception init!!");
      when height_too_large =>
         Ada.Text_IO.Put_Line("height is too large init");
      return TempCreature;
   end Init;

   function Init return Creature is --default constructor
      TempCreature : Creature;
   begin
      TempCreature.Name := Ada.Strings.Unbounded.To_Unbounded_String ("dog");
      TempCreature.Legs          := 4;
      TempCreature.WeightInGrams := 3_000;
      TempCreature.HeightInCm    := 40;
      return TempCreature;
   end Init;

   procedure Set_Legs (Creat : in out Creature; Legs : in Natural ) is
   begin
      set_legs_private(creat,legs);
   exception
      when too_many_legs_exception =>
         Ada.Text_IO.Put_Line("too many legs excpetion set!");
   end set_legs;

   procedure Set_Legs_Private (Creat : in out Creature; Legs : in Natural) is
   begin
      if (legs > 1000) then
         raise too_many_legs_exception;
         end if;
      Creat.Legs := Legs;
   end Set_Legs_private;
   procedure Set_Weight (Creat : in out Creature; WeightInGrams : in Positive)
   is
   begin
      creat.weightingrams := weightingrams;
      --set_weight_private(creat,weightingrams)l
      --exception
   end Set_Weight;

   --procedure set_weight_private (creat : in out Creature; Weightingrams : in Positive)
   --is
   --begin
   --   if (weight
   --   Creat.WeightInGrams := WeightInGrams;
   --end

   procedure Set_Height (Creat : in out Creature; HeightInCm : in Positive) is
   begin
      --Creat.HeightInCm := HeightInCm;
      set_height_private (creat, heightincm);
   exception
      when height_too_large =>
         Ada.Text_IO.Put_Line("height is too large exception set!!!");
   end Set_Height;

   procedure set_height_private(creat : in out Creature; heightincm : in positive) is
   begin
      if (heightincm > 2000) then
         raise height_too_large;
         end if;

      creat.heightincm := heightincm;
   end set_height_private;

   function Get_Legs (Creat : in out Creature) return Natural is
   begin
      return Creat.Legs;
   end Get_Legs;
   function Get_Weight (Creat : in out Creature) return Positive is
   begin
      return Creat.WeightInGrams;
   end Get_Weight;
   function Get_Height (Creat : in out Creature) return Positive is
   begin
      return Creat.HeightInCm;
   end Get_Height;
   function get_name (creat : in out Creature) return Ada.Strings.Unbounded.Unbounded_String is
   begin
     return creat.name;
   end get_name;

   overriding procedure Finalize (Creat : in out Creature) is
   begin
      Ada.Text_IO.Put_Line ("Resetting values of Creat to defaults.");
      Creat.Name          := Ada.Strings.Unbounded.Null_Unbounded_String;
      Creat.Legs          := 0;
      Creat.WeightInGrams := 1;
      Creat.HeightInCm    := 1;
   end Finalize;
   procedure Print_Record (Creat : in out Creature) is
   begin
      Private_Print_Record (Creat);
   end Print_Record;
   procedure Private_Print_Record (Creat : in out Creature) is
   begin
      Ada.Text_IO.Put_Line (" The animal:");
      Ada.Text_IO.Put_Line
        (" The name: " & Ada.Strings.Unbounded.To_String (Creat.Name));
      Ada.Text_IO.Put_Line (" Number of legs: " & Natural'Image (Creat.Legs));
      Ada.Text_IO.Put_Line
        (" Weight in grams: " & Positive'Image (Creat.WeightInGrams));
      Ada.Text_IO.Put_Line
        (" Height in cm: " & Positive'Image (Creat.HeightInCm));
   end Private_Print_Record;
end Animal;
