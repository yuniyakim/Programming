﻿using System;

namespace _2._1
{
    public class List
    {
        private class Node
        {
            public Node(string value, int position)
            {
                this.value = value;
                this.position = position;
                next = null;
            }

            public string Value
            {
                get
                {
                    return value;
                }
                set
                {
                    this.value = value;
                }
            }

            public int Position
            {
                get
                {
                    return position;
                }
                set
                {
                    position = value;
                }
            }

            public Node Next
            {
                get
                {
                    return next;
                }
                set
                {
                    next = value;
                }
            }

            private string value;
            private int position;
            private Node next;
        }

        public List()
        {
            head = null;
            Length = 0;
        }

        public bool IsEmpty { get => Length == 0; }

        private bool IsContained(int position) => !(IsEmpty || position > Length || position < 1);

        public void Print()
        {
            if (IsEmpty)
            {
                Console.WriteLine("List is empty");
            }
            else
            {
                var temp = head;
                for (int i = 0; i < Length; ++i)
                {
                    Console.WriteLine($"Value: {temp.Value}, position: {temp.Position}");
                    if (temp.Next != null)
                    {
                        temp = temp.Next;
                    }
                }
            }
        }

        private void Renumbering()
        {
            var temp = head;
            for (int i = 1; i <= Length; ++i)
            {
                temp.Position = i;
                if (temp.Next != null)
                {
                    temp = temp.Next;
                }
            }
        }

        public void Push(string value, int position)
        {
            if (IsEmpty)
            {
                head = new Node(value, 1);
                ++Length;
            }
            else if (position > Length + 1 || position < 1)
            {
                Console.WriteLine("Invalid position");
            }
            else
            {
                var newElement = new Node(value, position);
                if (position == 1)
                {
                    newElement.Next = head;
                    head = newElement;
                    ++Length;
                    Renumbering();
                }
                else
                {
                    var temp = head;
                    for (int i = 1; i < position - 1; ++i)
                    {
                        if (temp.Next != null)
                        {
                            temp = temp.Next;
                        }
                    }
                    newElement.Next = temp.Next;
                    temp.Next = newElement;
                    ++Length;
                    Renumbering();
                }
            }
        }

        public void Delete(int position)
        {
            if (IsEmpty)
            {
                Console.WriteLine("List is empty");
            }
            else if (!IsContained(position))
            {
                Console.WriteLine("Invalid position");
            }
            else
            {
                if (position == 1)
                {
                    if (Length == 1)
                    {
                        head = null;
                    }
                    else
                    {
                        head = head.Next;
                    }
                }
                else
                {
                    var temp = head;
                    for (int i = 1; i < position - 1; ++i)
                    {
                        temp = temp.Next;
                    }
                    if (position == Length)
                    {
                        temp.Next = null;
                    }
                    else
                    {
                        temp.Next = temp.Next.Next;
                    }
                }
                --Length;
            }
            Renumbering();
        }

        public void PrintValueByPosition(int position)
        {
            if (IsEmpty)
            {
                Console.WriteLine("List is empty");
            }
            else if (!IsContained(position))
            {
                Console.WriteLine("List overflow");
            }
            else
            {
                var temp = head;
                for (int i = 1; i < position; ++i)
                {
                    temp = temp.Next;
                }
                Console.WriteLine($"Value: {temp.Value}, position: {temp.Position}");
            }
        }

        public void SetValue(string value, int position)
        {
            if (IsEmpty)
            {
                Console.WriteLine("List is empty");
            }
            else if (!IsContained(position))
            {
                Console.WriteLine("List overflow");
            }
            else
            {
                var temp = head;
                for (int i = 1; i < position; ++i)
                {
                    temp = temp.Next;
                }
                temp.Value = value;
            }
        }

        private Node head;
        public int Length { get; set; }
    }
}

/* Написать связный список в виде класса. От списка хочется:
- Добавлять/удалять элемент по произвольной позиции, задаваемой целым числом
- Узнавать размер, проверять на пустоту
- Получать или устанавливать значение элемента по позиции, задаваемой целым числом */
